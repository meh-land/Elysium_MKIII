def inverse_kinematics(vx, vy, w, wheel_radius, wheel_base):
"""

Compute the wheel speeds for a differential drive robot.


Parameters:
vx (float): Linear velocity in the x direction.
vy (float): Linear velocity in the y direction (should be zero for differential drive).
w (float): Angular velocity.
wheel_radius (float): Radius of the wheels.
wheel_base (float): Distance between the wheels.

Returns:
(float, float): Speed of the left and right wheels.
"""
v_left = (vx - (w * wheel_base / 2)) / wheel_radius
v_right = (vx + (w * wheel_base / 2)) / wheel_radius
return v_left, v_right