
// //Viêt churong trinh có khai báo các hàm dê thurc hiên các công viêc sau
// - Nhâp däy n sô nguyên (3<=n<=10)
// In dây sô
// Tính tôn các só nguyên tô vó trong day
// Sáp xêp dây theo thú tu täng dân
// - Nhâp sô nguyên k bât ky, tim xem k trong däy sô trên hay khöng?
// Nêu có, hay cho biét vi trí tim thây

#include <iostream>
#include <cmath>
using namespace std;

void nhapMang(int n, int dayso[])
{
  for (int i = 0; i <= n; i++)
  {
    cout << "dayso[" << i << "]: ";
    cin >> dayso[i];
  }
}

void xuatMang(int n, int dayso[])
{
  for (int i = 0; i <= n; i++)
  {
    cout << dayso[i] << "  ";
  }
}

int kiemTraSnt(int n)
{
  if (n < 2)
  {
    return 0;
  }

  int canBac2 = (int)sqrt(n);

  for (int i = 2; i <= canBac2; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }

  return 1;
}

int tongSoNguyenTo(int n, int dayso[])
{
  int t = 0;
  for (int i = 0; i <= n; i++)
  {
    if (kiemTraSnt(dayso[i]))
    {
      t += dayso[i];
    }
  }

  return t;
}

void swap(int &a, int &b)
{
  int c = a;
  a = b;
  b = c;
}

void sapXepTang(int n, int dayso[])
{
  for (int i = 0; i <= n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (dayso[i] > dayso[j])
      {
        swap(dayso[i], dayso[j]);
      }
    }
  }

  cout << "Day sau khi sap xep tang dan la: ";
  for (int i = 0; i <= n; i++)
  {
    cout << dayso[i] << " ";
  }
}

// mảng đã sắp xếp thì ta có thể dùng binary search

void check_k_VaThongBao_k(int n, int dayso[], int k)
{
  int co = 0;
  for (int i = 0; i <= n; i++)
  {
    if (k == dayso[i])
    {
      co++;
      cout << "Co so k o trong day so, va k nam o vi tri: " << i << "\n";
    }
  }

  if (co == 0)
  {
    cout << "Khong co k trong day so.";
  }
}

int main()
{
  int n;

  cout << "Nhap so nguyen n(3<=n<=10): ";
  cin >> n;

  while ((n < 3) || (n > 10))
  {
    cout << "Ban nhap sai voi dieu kien la (3<=n<=10), moi ban nhap lai: n = ";
    cin >> n;
  }

  int daySo[n];
  nhapMang(n, daySo);

  cout << "day so da nhap la: ";
  xuatMang(n, daySo);

  cout << "\ntong cac so nguyen to co trong day la: " << tongSoNguyenTo(n, daySo) << "\n";
  sapXepTang(n, daySo);

  int k;
  cout << "\nNhap so k: ";
  cin >> k;

  check_k_VaThongBao_k(n, daySo, k);

  return 0;
}