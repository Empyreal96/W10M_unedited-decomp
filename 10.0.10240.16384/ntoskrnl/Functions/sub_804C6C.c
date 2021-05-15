// sub_804C6C 
 
void sub_804C6C(int a1, int a2, int a3, int a4, ...)
{
  unsigned int *v4; // r5
  int v5; // r6
  unsigned int *v6; // r7
  int v7; // r8
  int v8; // r0
  int v9; // r4
  _DWORD *v10; // r4
  int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r2
  int v14; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  va_list va1; // [sp+4h] [bp+4h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  while ( 1 )
  {
    v14 = va_arg(va1, _DWORD);
    v8 = CmListGetNextElement(v5 + 108, va1, 16);
    v9 = v8;
    if ( !v8 )
      break;
    if ( CmEqualTrans(*(_DWORD *)(v8 + 28), v7) )
    {
      if ( *(_DWORD *)(v9 + 36) == 1 )
      {
        v10 = *(_DWORD **)(v9 + 48);
        if ( (v10[1] & 0x20000) == 0 )
        {
          v11 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v10[5] + 4))(v10[5], v10[6], (int *)va);
          if ( !v11 )
            JUMPOUT(0x74DD4E);
          v12 = *(unsigned __int16 *)(v11 + 52);
          if ( *v6 < v12 )
            *v6 = v12;
          if ( v4 )
          {
            v13 = *(_DWORD *)(v11 + 56);
            if ( *v4 < v13 )
              *v4 = v13;
          }
          (*(void (__fastcall **)(_DWORD, int *))(v10[5] + 8))(v10[5], (int *)va);
        }
      }
    }
  }
  JUMPOUT(0x74DD4C);
}
