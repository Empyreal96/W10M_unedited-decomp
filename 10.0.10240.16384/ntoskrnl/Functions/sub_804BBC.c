// sub_804BBC 
 
void sub_804BBC(unsigned int a1, int a2, int a3, int a4, ...)
{
  _DWORD *v4; // r5
  unsigned int *v5; // r6
  unsigned int *v6; // r7
  int v7; // r3
  int *v8; // r9
  int v9; // r8
  int v10; // t1
  int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r2
  int v14; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  va_list va1; // [sp+4h] [bp+4h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v14 = va_arg(va1, _DWORD);
  v7 = v4[38];
  if ( v7 )
  {
    if ( v7 == a3 )
    {
      *v6 = a1;
      *v5 = a1;
      if ( v4[36] )
      {
        v8 = (int *)(*(int (__fastcall **)(_DWORD, _DWORD, int *))(v4[5] + 4))(v4[5], v4[37], (int *)va);
        if ( !v8 )
          goto LABEL_21;
        v9 = 0;
        if ( v4[36] )
        {
          while ( 1 )
          {
            v10 = *v8++;
            v11 = (*(int (__fastcall **)(_DWORD, int, void **))(v4[5] + 4))(v4[5], v10, va1);
            if ( !v11 )
              break;
            if ( (*(_WORD *)(v11 + 16) & 1) != 0 )
              v12 = (unsigned __int16)(2 * *(_WORD *)(v11 + 2));
            else
              v12 = *(unsigned __int16 *)(v11 + 2);
            if ( *v6 < v12 )
              *v6 = v12;
            v13 = *(_DWORD *)(v11 + 4);
            if ( v13 >= 0x80000000 )
              v13 += 0x80000000;
            if ( *v5 < v13 )
              *v5 = v13;
            (*(void (__fastcall **)(_DWORD, void **))(v4[5] + 8))(v4[5], va1);
            if ( (unsigned int)++v9 >= v4[36] )
              goto LABEL_19;
          }
          (*(void (__fastcall **)(_DWORD, int *))(v4[5] + 8))(v4[5], (int *)va);
LABEL_21:
          JUMPOUT(0x74DD0E);
        }
LABEL_19:
        (*(void (__fastcall **)(_DWORD, int *))(v4[5] + 8))(v4[5], (int *)va);
      }
    }
  }
  JUMPOUT(0x74DD0C);
}
