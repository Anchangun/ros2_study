#ifndef RCLCPP__TYPE_ADAPTER_HPP_
#define RCLCPP__TYPE_ADAPTER_HPP_

#include <type_traits>

namespace rclcpp
{
template<typename CustomType, typename ROSMessageType = void, class Enable = void>
struct TypeAdapter
{
  using is_specialized = std::false_type;
  using custom_type = CustomType;
  // In this case, the CustomType is the only thing given, or there is no specialization.
  // Assign ros_message_type to CustomType for the former case.
  using ros_message_type = CustomType;
};

template<typename T>
struct is_type_adapter : std::false_type {};

template<typename ... Ts>
struct is_type_adapter<TypeAdapter<Ts...>>: std::true_type {};

template<typename T>
struct TypeAdapter<T, void, std::enable_if_t<is_type_adapter<T>::value>>: T {};

namespace detail
{

template<typename CustomType, typename ROSMessageType>
struct assert_type_pair_is_specialized_type_adapter
{
  using type_adapter = TypeAdapter<CustomType, ROSMessageType>;
  static_assert(
    type_adapter::is_specialized::value,
    "No type adapter for this custom type/ros message type pair");
};

}  // namespace detail

template<typename CustomType>
struct adapt_type
{
  template<typename ROSMessageType>
  using as = typename ::rclcpp::detail::assert_type_pair_is_specialized_type_adapter<
    CustomType,
    ROSMessageType
    >::type_adapter;
};


template<typename CustomType>
struct ImplicitTypeAdapter
{
  using is_specialized = std::false_type;
};


template<typename T>
struct TypeAdapter<T, void, std::enable_if_t<ImplicitTypeAdapter<T>::is_specialized::value>>
  : ImplicitTypeAdapter<T>
{};


#define RCLCPP_USING_CUSTOM_TYPE_AS_ROS_MESSAGE_TYPE(CustomType, ROSMessageType) \
  template<> \
  struct rclcpp::ImplicitTypeAdapter<CustomType> \
    : public rclcpp::TypeAdapter<CustomType, ROSMessageType> \
  { \
    static_assert( \
      is_specialized::value, \
      "Cannot use custom type as ros type when there is no TypeAdapter for that pair"); \
  }

}  // namespace rclcpp

#endif  // RCLCPP__TYPE_ADAPTER_HPP_
