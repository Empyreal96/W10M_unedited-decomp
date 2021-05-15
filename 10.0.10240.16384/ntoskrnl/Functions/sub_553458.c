// sub_553458 
 
// bad sp value at call has been detected, the output may be wrong!
void __fastcall sub_553458(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _BYTE *a8)
{
  int v8; // r5
  int v9; // r7
  int *v10; // r8
  _BYTE *v11; // r0
  _BYTE *v12; // r4
  int v13; // r0
  int v14; // r6

  v11 = (_BYTE *)ExAllocatePoolWithTag(1, 48);
  v12 = v11;
  a8 = v11;
  if ( v11 )
  {
    memset(v11, 0, 48);
    *((_DWORD *)v12 + 10) = v8;
    *((_DWORD *)v12 + 11) = a5;
    v13 = RtlpCreateHashTable((int *)&a8, 0x80u, 0, 0);
    v14 = (int)a8;
    if ( v13 && SepReadAndInsertCaps(a6, v9, a8) >= 0 )
    {
      *v10 = v14;
    }
    else if ( v14 )
    {
      SepRmDestroyCapTable(v14);
    }
    JUMPOUT(0x4F3692);
  }
  JUMPOUT(0x4F36B6);
}
