###thread_executor_test
Thread Executor Test Package
One is the main node that calls callback in a multi-thread manner
The other node is publishing continuously with pub

### Compile
```
colcon build --packages-select thread_excute_test
```

### Test
```
ros2 run thread_execute_main

+ Other Terminal
ros2 run thread_execute_pub "test_one"
+ Other Terminal
ros2 run thread_execute_pub "test_two"
```

### Rerference
* https://docs.ros.org/en/foxy/Concepts/About-Executors.html
