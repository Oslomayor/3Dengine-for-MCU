# 3Dengine-for-MCU
跑在单片机上的轻量级3D引擎

## 数学原理
|   Point   | Rotate via | theta |           New Point            |
| :-------: | :--------: | :---: | :----------------------------: |
|           |     z      |       | (xcosθ-ysinθ, ycosθ+xsinθ, z)  |
| (x, y, z) |     y      |   θ   | (xcosθ+zsinθ, y, zcosθ-xsinθ)  |
|           |     x      |       | (x, ycosθ-zsinθ,  zcosθ+ysinθ) |
