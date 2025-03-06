# Báo cáo Bài tập lớn - Nhóm 10

## 1. Thông tin nhóm
| STT | Họ và tên | MSSV | Vai trò |
|---|---|---|---|
| 1 | Nguyễn Đức Anh | 24022763 | Nhóm trưởng |
| 2 | Dương Minh Vũ | 24022844 | Thành viên |
| 3 | Hoàng Tuấn Đạt | 24022773 | Thành viên |
| 4 | Hà Minh Vũ | 24022845 | Thành viên |
| 5 | Nguyễn Đăng Mạnh | 24022815 | Thành viên |

---

## 2. Thông tin bài tập
- **Tên bài toán**: Bài 5: Bài toán N-Queens (N Quân Hậu)
- **Đề bài**: Trên bàn cờ NxN, cần đặt N quân hậu sao cho không quân hậu nào ăn nhau. Quân hậu có thể ăn các ô nằm cùng hàng, cùng cột, cùng đường chéo.
- **Gợi ý**:
  - Duyệt từng dòng, mỗi dòng đặt 1 quân hậu.
  - Đệ quy sang dòng tiếp theo, kiểm tra tính hợp lệ trước khi đặt.
 
---

## 3. Hướng giải quyết bài toán
### a. Phân tích bài toán
- **Mô tả**:
  - Đầu vào: 1 số `N` (đại diện cho kích thước của bàn cờ `NxN` và số lượng quân hậu đặt trên bàn cờ đó)
  - Đầu ra: số lượng cách xếp bàn cờ và sơ đồ của từng bàn cờ (với số `0` là ô cờ trống, số từ `1` đến `N` là số thứ tự của `N` quân hậu)
  - Ví dụ: với `N = 4` thì có 2 cách đặt thỏa mãn như sau:
    
    ![Image](https://github.com/user-attachments/assets/544a646b-08dc-4958-9e1c-c793bfac2e35)


- **Nhận xét**:
  - Chúng ta cần đặt `N` quân hậu sau cho trên mỗi hàng, một cột, mỗi đường chéo của bàn cờ chỉ chứa tối đa một quân hậu, như vậy trên mỗi hàng sẽ có đúng 1 quân hậu được đặt.
  - Mỗi con hậu trên bàn cờ sẽ quản lý **hàng ngang**, **cột dọc**, **đường chéo xuôi** và **đường chéo ngược**:
      
    ![Image](https://github.com/user-attachments/assets/d5597998-7924-47ec-826f-0a55957e42fc)


### b. Thuật toán/Hướng tiếp cận
####  **Ý TƯỞNG CHÍNH**
Thuật toán sử dụng phương pháp **đệ quy quay lui** để thử từng vị trí đặt quân hậu trên bàn cờ và kiểm tra tính hợp lệ. Các bước thực hiện:
- **Bước 1:** **Bắt đầu từ hàng đầu tiên `(i = 1)`.**
- **Bước 2:** **Thử đặt quân hậu vào từng cột trong hàng hiện tại `(j = 1 → N)`.**
- **Bước 3:** **Kiểm tra xem vị trí `(i, j)` có hợp lệ không:**
  - Không có quân hậu nào trong cùng **cột**: Sử dụng mảng `bool col` để đánh dấu các cột của bàn cờ ( `col[i] = true` nếu trên cột i chưa đặt quân hậu nào )
  - Không có quân hậu nào trên **đường chéo xuôi**: Sử dụng mảng `bool dia1` để đánh dấu **đường chéo xuôi** mà con hậu quản lý ( `dia1[i - j + n] == true` nếu đường chéo chính chưa đặt quân hậu nào ) 
  - Không có quân hậu nào trên **đường chéo ngược**: Sử dụng mảng `bool dia1` để đánh dấu **đường chéo ngược** mà con hậu quản lý ( `dia2[i +  j - 1] == true` nếu đường chéo chính chưa đặt quân hậu nào ) 
- **Bước 4:** **Nếu vị trí hợp lệ:**
  - Đặt quân hậu vào vị trí đó.
  - Lưu vị trí đó vào mảng `queen` với giá trị là hàng `i` và chỉ số là cột `j`
  - Gọi đệ quy để đặt quân hậu ở hàng tiếp theo `(i + 1)` 
- **Bước 5:** **Nếu đặt xong tất cả `N` quân hậu, in ra một cách giải hợp lệ.**
- **Bước 6:** **Nếu không tìm thấy cách đặt hợp lệ ở hàng `i`, quay lui:**
  - Gỡ bỏ quân hậu vừa đặt.
  - Thử vị trí khác trong cùng hàng.
 

#### **MÃ GIẢ**
- HÀM **Print_Result()**
  - **TĂNG** biến đếm `cnt`
  - **IN** ra cách đặt quân hậu hiện tại trên bàn cờ (phần tử `queen[i]` có **giá trị** là số hàng và chỉ số `i` ứng với số cột nên khi đúng vị trí `(hàng, cột)` đó thì in ra **thứ tự** quân hậu, còn lại in ra `0`)  

- HÀM **Can_Place_Queen(int i, int j)**
    **ĐIỀU KIỆN** là  `col[j] == true` (cột trống) VÀ `dia1[i - j + n] == true` (đường chéo chính trống) VÀ `dia2[i + j - 1] == true` (đường chéo phụ trống)
  => có thể đặt quân hậu

- HÀM **Place_Queen(int i)**
  - **DUYỆT** qua từng cột `j` từ `1` đến `n`
       - NẾU `Can_Place_Queen(i, j, n)` LÀ true
            - **GÁN** `queen[j] = i` (đặt quân hậu vào hàng i, cột j)
                - `col[j] = false` (đánh dấu **cột** đã bị chiếm)
                - `dia1[i - j + n] = false` (đánh dấu **đường chéo chính** đã bị chiếm)
                - `dia2[i + j - 1] = false` (đánh dấu **đường chéo phụ** đã bị chiếm)

            - NẾU `i == n` (đã đặt hết quân hậu)
                - **GỌI** `Print_Result()`
            - NGƯỢC LẠI
                - **GỌI ĐỆ QUY** `Place_Queen(i + 1)`
                - **LOẠI BỎ** quân hậu bằng cách gán lại giá trị ban đầu:
                    - `col[j] =  dia1[i - j + n] = dia2[i + j - 1] = true`
  - KẾT THÚC LẶP
  
- HÀM **main()**
    - Đọc giá trị `n` (số quân hậu)
    - **KHỞI TẠO** mảng `col`, `dia1`, `dia2` với giá trị ban đầu là true
    - **GỌI** Place_Queen(1)
    - **IN** số cách đặt quân hậu hợp lệ



#### **SƠ ĐỒ KHỐI**

  ![Image](https://github.com/user-attachments/assets/2222b2df-b04d-44ca-a102-6da7157b2510)
#### **ĐÁNH GIÁ ĐỘ PHỨC TẠP**
- Mảng **trạng thái**: `queen[N]` → O(N)
- Mảng **Boolean**: `col[N]`, `dia1[2N]`, `dia2[2N]` → O(N)
- **Đệ quy** sâu tối đa `N` → O(N)

 => Tổng **độ phức tạp**: O(N) + O(N) + O(N) = **O(N)**


 
 #### **WEB MINH HỌA THUẬT TOÁN**
https://liveexample.pearsoncmg.com/dsanimation/EightQueenseBook.html



---

## 4. Ví dụ minh hoạ
### Ví dụ 1
**Input:**  
N = 4

**Output:**  

![Image](https://github.com/user-attachments/assets/76e2823c-a32e-4463-96b9-b0133960aa93)

**Giải thích:**  
Có `2` cách sắp xếp hợp lệ
- **Cách 1**:
  - Quân hậu hàng `1` ở cột `2`.
  - Quân hậu hàng `2` ở cột `4`.
  - Quân hậu hàng `3` ở cột `1`.
  - Quân hậu hàng `4` ở cột `3`.
- **Cách 2**:
  - Quân hậu hàng `1` ở cột `3`.
  - Quân hậu hàng `2` ở cột `1`.
  - Quân hậu hàng `3` ở cột `4`.
  - Quân hậu hàng `4` ở cột `2`.   

### Ví dụ 2
**Input:**  
N = 3

**Output:**  

![Image](https://github.com/user-attachments/assets/9b5dcbe6-206c-4b7c-bba6-f82e7cc6e53a) 

**Giải thích:**  
Trên bàn cờ `3x3`, không thể đặt cùng lúc `3` quân hậu sao cho các quân hậu không nằm trên đường đi của nhau

### Ví dụ 3
**Input:**  
N = 8 
**Output:**  

![Image](https://github.com/user-attachments/assets/e5e80acb-705d-48a1-9a7a-3f9b462a6fdc)

**Giải thích:**  
Có `92` cách sắp xếp hợp lệ

In ra là thứ tự các cách và bàn cờ `8x8` với các quân hậu đã được sắp xếp thỏa mãn bài toán.


---


## 5. Link video báo cáo
https://drive.google.com/file/d/1Qm9uDCwNg-JOUsGQuc6l863jVQWgCB1d/view?usp=sharing

---


## 6. Link source code
[Thư mục src](./src)

---


## 7. Ưu và nhược điểm

### **Ưu điểm**
- Tìm tất cả các cách đặt hậu hợp lệ, in ra cả bàn cờ trực quan, dễ hiểu
- Không yêu cầu thêm bộ nhớ đáng kể
- Hoạt động tốt với n nhỏ
  - Với kích thước bàn cờ nhỏ (n ≤ 10), thuật toán chạy khá nhanh và có thể duyệt qua toàn bộ không gian nghiệm trong thời gian hợp lý.

### **Nhược điểm**
- Hiệu suất kém khi n lớn
- Ví dụ:
    - n = 8 → 92 cách đặt hợp lệ (chấp nhận được).
    - n = 12  → 14200 cách đặt hậu (bắt đầu chậm).
    - n =  20  → gần 4 tỷ cách (quá chậm để chạy thực tế).
