// sub_813D88 
 
void sub_813D88(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  unsigned int v6; // r4
  _DWORD *v7; // r8
  int v8; // r0
  bool *v9; // r0
  _DWORD *v10; // r0
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( a4 != 3 )
  {
    if ( a4 == 5 )
    {
      if ( v6 != 8 )
        goto LABEL_20;
      v10 = (_DWORD *)ExAllocatePoolWithTag(1, 8, 1262764866);
      if ( !v10 )
        goto LABEL_18;
      *v10 = *v7;
      v10[1] = v7[1];
    }
    else
    {
      if ( a4 != 6 )
      {
        if ( a4 != 7 || (v6 & 7) == 0 )
        {
          v8 = ExAllocatePoolWithTag(1, v6, 1262764866);
          if ( v8 )
          {
            memmove(v8, (int)v7, v6);
            goto LABEL_19;
          }
LABEL_18:
          JUMPOUT(0x7A6DEA);
        }
LABEL_20:
        JUMPOUT(0x7A6D3E);
      }
      if ( v6 - 1 > 1 )
        goto LABEL_20;
      v9 = (bool *)ExAllocatePoolWithTag(1, 1, 1262764866);
      if ( !v9 )
        goto LABEL_18;
      *v9 = *(_BYTE *)v7 != 0;
    }
LABEL_19:
    JUMPOUT(0x7A6D34);
  }
  if ( v6 == 16 && RtlStringFromGUIDEx((int)v7, (int)va, 1) >= 0 )
    JUMPOUT(0x7A6D2E);
  goto LABEL_20;
}
