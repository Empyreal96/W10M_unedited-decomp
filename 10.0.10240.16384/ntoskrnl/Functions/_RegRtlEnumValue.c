// _RegRtlEnumValue 
 
int __fastcall RegRtlEnumValue(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6, _DWORD *a7)
{
  int v9; // r4
  unsigned int v10; // r5
  _DWORD *v11; // r5
  int v12; // r0
  int v13; // r1
  unsigned int v14; // r2
  int v15; // r7
  unsigned int v16; // r2
  unsigned int v17; // [sp+8h] [bp-28h] BYREF
  int v18; // [sp+Ch] [bp-24h]

  v18 = a3;
  if ( !a7 )
    return sub_7F040C();
  v9 = RtlULongLongToULong(2 * *a4, (unsigned __int64)(unsigned int)*a4 >> 31, &v17);
  if ( v9 >= 0 )
  {
    v10 = v17 + 24;
    if ( v17 + 24 < v17 || *a7 + v10 < v10 )
    {
      v9 = -1073741675;
    }
    else
    {
      v11 = (_DWORD *)ExAllocatePoolWithTag(1, *a7 + v10, 1279739218);
      if ( v11 )
      {
        v12 = ZwEnumerateValueKey();
        v9 = v12;
        if ( !v12 || v12 == -2147483643 )
        {
          if ( a5 )
            *a5 = v11[1];
          if ( v12 || (v13 = v11[4] >> 1, *a4 < (unsigned int)(v13 + 1)) || (v14 = v11[3], *a7 < v14) )
          {
            *a4 = (v11[4] >> 1) + 1;
            *a7 = v11[3];
            v9 = -1073741789;
          }
          else
          {
            *a7 = v14;
            v15 = v18;
            v16 = v11[4];
            *a4 = v13;
            memmove(v15, (int)(v11 + 5), v16);
            *(_WORD *)(v15 + 2 * *a4) = 0;
            memmove(a6, (int)v11 + v11[2], v11[3]);
          }
        }
        ExFreePoolWithTag((unsigned int)v11);
      }
      else
      {
        v9 = -1073741801;
      }
    }
  }
  return v9;
}
