---

# PS5 Simulator

## Giới thiệu

Đây là project mô phỏng tay cầm chơi game PS5 sử dụng vi điều khiển STM32F429ZIT6. Thiết bị được nhận diện như một thiết bị HID (bàn phím và chuột) khi kết nối với máy tính qua cổng USB, cho phép điều khiển game hoặc các ứng dụng khác bằng các nút bấm vật lý và joystick.

---

## Cài đặt

### 1. Clone project

```bash
git clone https://github.com/MinhHoang137/ps5_simulator.git
```

### 2. Yêu cầu phần cứng

- Vi điều khiển: **STM32F429ZIT6**
- Cáp USB kết nối máy tính
- Các nút bấm, joystick, LED, linh kiện phụ trợ theo sơ đồ mạch

### 3. Yêu cầu phần mềm

- **STM32CubeIDE** (khuyến nghị phiên bản >= 1.10.0)
- **STM32CubeMX** (nếu muốn chỉnh sửa cấu hình phần cứng, >= 6.5.0)
- **ST-Link Utility** hoặc STM32CubeProgrammer (để nạp firmware)

### 4. Hướng dẫn build & nạp firmware

1. Mở project bằng **STM32CubeIDE**:
    - File project: `ps5_simulator/.project`
2. Build project (Ctrl + B hoặc nút hammer).
3. Kết nối board với máy tính qua cáp USB.
4. Nạp firmware lên board (nút "Debug" hoặc "Run" trong IDE).
5. Sau khi nạp xong, board sẽ được máy tính nhận diện là thiết bị HID (bàn phím/chuột).

---

## Thông tin thêm

- **Ngôn ngữ lập trình:** C
- **Thư viện sử dụng:** STM32 HAL, STM32 USB Device Library (HID)
- **Hệ điều hành hỗ trợ:** Windows, Linux, macOS (không cần driver riêng)
- **Tác giả:** [MinhHoang137](https://github.com/MinhHoang137), LyMuc, NHP234
