// sub_51C458 
 
void __fastcall sub_51C458(int a1, unsigned int a2, int a3, int a4, _DWORD *a5, int a6, _DWORD *a7, int a8)
{
  _DWORD *v8; // r0
  _DWORD *v9; // r2
  unsigned int v10; // [sp+BCh] [bp+1Ch]

  if ( !a8 )
  {
    v10 = a2 >> 1;
    v8 = (_DWORD *)ExAllocatePoolWithTag(512, 8 * ((a2 >> 1) + 1));
    if ( !v8 )
      RtlRaiseStatus(-1073741801);
    *v8 = *a5;
    v8[1] = a5[1];
    v8[2] = a5[2];
    v8[3] = a5[3];
    v8[4] = a5[4];
    v8[5] = a5[5];
    v8[6] = a5[6];
    v8[7] = a5[7];
    v9 = &v8[v10];
    v9[1] = *a7;
    v9[2] = a7[1];
    v9[3] = a7[2];
    v9[4] = a7[3];
    v9[5] = a7[4];
    v9[6] = a7[5];
    v9[7] = a7[6];
    v9[8] = a7[7];
  }
  JUMPOUT(0x44733E);
}
