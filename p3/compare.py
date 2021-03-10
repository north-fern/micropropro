import matplotlib.pyplot as plt
import numpy as np
import time

fig, ax=plt.subplots()
time_start = time.time()

# Setup Problem
time_stop = 4
num_steps = 1000000
time_base_unit = time_stop / num_steps

Ixx = 1
Iyy = 2
Izz = 3
time_now = 0

# Initial Values wx, wy, wz

wx = .2
wy = 7
wz = .2

wx_collect = [float(wx)]
wy_collect = [float(wy)]
wz_collect = [float(wz)]
time_collect = [float(time_now)]

while time_now < time_stop:
    wxdot = (Iyy-Izz)*wz*wy/Ixx
    wydot = (Izz-Ixx)*wz*wx/Iyy
    wzdot = (Ixx-Iyy)*wy*wx/Izz

    wz_old = wxdot*Ixx/(wy*(Iyy-Izz))
    wx_old = wydot*Iyy/(wz*(Izz-Ixx))
    wy_old = wzdot*Izz/(wx*(Ixx-Iyy))

    wx = wxdot*time_base_unit + wx_old
    wy = wydot*time_base_unit + wy_old
    wz = wzdot*time_base_unit + wz_old

    wx_collect.append(wx)
    wy_collect.append(wy)
    wz_collect.append(wz)
    time_collect.append(time_now)

    time_now += time_base_unit

print(wx, wy, wz)

line1, = ax.plot(time_collect, wx_collect, label = 'wx')
line2, = ax.plot(time_collect, wy_collect, label = 'wy')
line3, = ax.plot(time_collect, wz_collect, label = 'wz')
ax.legend()
plt.figure(1)
plt.show()
plt.close()
total_time = time.time() - time_start
print(total_time)


time_start = time.time()

# Setup Problem

time_stop = 4
num_steps = 1000000
time_base_unit = time_stop / num_steps

def forward_euler(wx, wy, wz, time_now):
    time_stop = 4
    num_steps = 1000000
    time_base_unit = time_stop / num_steps

    Ixx = 1
    Iyy = 2
    Izz = 3
    
    wxdot = (Iyy-Izz)*wz*wy/Ixx
    wydot = (Izz-Ixx)*wz*wx/Iyy
    wzdot = (Ixx-Iyy)*wy*wx/Izz

    wz_old = wxdot*Ixx/(wy*(Iyy-Izz))
    wx_old = wydot*Iyy/(wz*(Izz-Ixx))
    wy_old = wzdot*Izz/(wx*(Ixx-Iyy))

    wx_new = wxdot*time_base_unit + wx_old
    wy_new = wydot*time_base_unit + wy_old
    wz_new = wzdot*time_base_unit + wz_old
    return wx_new, wy_new, wz_new

# Initial Values wx, wy, wz

wx = .2
wy = 7
wz = .2
time_now = 0
wx_collect = [float(wx)]
wy_collect = [float(wy)]
wz_collect = [float(wz)]
time_collect = [float(time_now)]

while time_now < time_stop:
    (wx_new, wy_new, wz_new) = forward_euler(wx, wy, wz, time_now)
    wx_collect.append(wx_new)
    wy_collect.append(wy_new)
    wz_collect.append(wz_new)
    time_collect.append(time_now)
    wx, wy, wz = wx_new, wy_new, wz_new
    time_now += time_base_unit

print(wx, wy, wz)

plot2 = plt.figure(2)
line1, = ax.plot(time_collect, wx_collect, label = 'wx')
line2, = ax.plot(time_collect, wy_collect, label = 'wy')
line3, = ax.plot(time_collect, wz_collect, label = 'wz')
ax.legend()
plt.show()
plt.close()
total_time = time.time() - time_start
print(total_time)

