// PspInitDeferredResourceReservation 
 
int __fastcall PspInitDeferredResourceReservation(int a1, int a2, int a3, int a4, int a5, int (__fastcall *a6)(int), int *a7)
{
  int (__fastcall *v7)(int); // r4
  int v8; // r5
  int *v9; // r6

  v7 = a6;
  v8 = a5;
  v9 = a7;
  do
    *v9-- = 0;
  while ( v9 >= &a5 );
  a5 = v8;
  return v7(a1);
}
