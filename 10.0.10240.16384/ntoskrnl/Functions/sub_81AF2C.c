// sub_81AF2C 
 
void sub_81AF2C(int a1, int a2, int a3, unsigned int *a4, ...)
{
  unsigned int *v4; // r5
  unsigned int v5; // r4
  unsigned int *v6; // r5
  unsigned int v7; // r8
  unsigned int v8; // t1
  unsigned int v9; // r4
  unsigned int v10; // r9
  _DWORD *v11; // r5
  unsigned int v12; // r7
  unsigned int v13; // t1
  unsigned int v14; // r4
  int v15; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  int v17; // [sp+4h] [bp+4h]
  int v18; // [sp+8h] [bp+8h]
  int v19; // [sp+Ch] [bp+Ch]
  void *v20; // [sp+10h] [bp+10h] BYREF
  va_list va1; // [sp+10h] [bp+10h]
  int v22; // [sp+14h] [bp+14h]
  int v23; // [sp+18h] [bp+18h]
  int v24; // [sp+1Ch] [bp+1Ch]
  va_list va2; // [sp+20h] [bp+20h] BYREF

  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v15 = va_arg(va1, _DWORD);
  v17 = va_arg(va1, _DWORD);
  v18 = va_arg(va1, _DWORD);
  v19 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v20 = va_arg(va2, void *);
  v22 = va_arg(va2, _DWORD);
  v23 = va_arg(va2, _DWORD);
  v24 = va_arg(va2, _DWORD);
  v5 = *a4;
  if ( *a4 )
  {
    if ( !SeILSigningPolicy && v5 >= 4 )
    {
      v8 = *v4;
      v6 = v4 + 1;
      v7 = v8;
      v9 = v5 - 4;
      if ( v8 <= 3 )
      {
        v10 = 0;
        if ( v7 )
        {
          while ( 1 )
          {
            if ( v9 < 4 )
              goto LABEL_15;
            v13 = *v6;
            v11 = v6 + 1;
            v12 = v13;
            v14 = v9 - 4;
            if ( v14 < v13 || v12 < 0x40 )
              goto LABEL_15;
            if ( (!memcmp((unsigned int)(v11 + 1), (unsigned int)va, 16)
               || !memcmp((unsigned int)(v11 + 1), (unsigned int)va1, 16)
               || !memcmp((unsigned int)(v11 + 1), (unsigned int)va2, 16))
              && (v11[9] & 4) != 0 )
            {
              break;
            }
            ++v10;
            v9 = v14 - v12;
            v6 = (_DWORD *)((char *)v11 + v12);
            if ( v10 >= v7 )
              goto LABEL_15;
          }
          SeILSigningPolicy = 2;
        }
      }
    }
  }
LABEL_15:
  JUMPOUT(0x7B94D2);
}
