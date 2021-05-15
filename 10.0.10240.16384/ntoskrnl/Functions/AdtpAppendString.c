// AdtpAppendString 
 
int __fastcall AdtpAppendString(int result, _BYTE *a2, int *a3, _DWORD *a4)
{
  _DWORD *v4; // r5
  int v5; // r7
  _WORD *v6; // r10
  unsigned __int16 *v8; // r1
  unsigned int v9; // r4
  int v10; // r2
  unsigned int v11; // r2
  unsigned __int16 *v12; // r6
  unsigned int v13; // r2
  int v14; // r5
  int v15; // r0
  int v16; // r9
  int v17; // r1
  _DWORD *v18; // [sp+0h] [bp-38h]
  _BYTE *v19; // [sp+4h] [bp-34h]
  unsigned __int16 *v20; // [sp+8h] [bp-30h]
  int v21[10]; // [sp+10h] [bp-28h] BYREF

  v4 = a4;
  v5 = *a4;
  v6 = (_WORD *)a3[1];
  v8 = (unsigned __int16 *)result;
  if ( v5 )
    result = 0;
  v18 = v4;
  v19 = a2;
  v20 = v8;
  v21[0] = *a3;
  if ( !v5 )
  {
    v9 = LOWORD(v21[0]);
    if ( LOWORD(v21[0]) )
    {
      while ( 1 )
      {
        if ( *a2 )
        {
          v10 = *v8;
          if ( v10 != 65534 )
          {
            v11 = (unsigned __int16)(v8[1] - v10);
            if ( *v6 != 37 || v11 >= v9 )
            {
              if ( v11 >= v9 )
                LOWORD(v11) = v9;
              v21[1] = (int)v6;
              v9 = (unsigned __int16)(v9 - v11);
              LOWORD(v21[0]) = v11;
              v6 = (_WORD *)((char *)v6 + (unsigned __int16)v11);
              RtlAppendUnicodeStringToString(v8, (unsigned __int16 *)v21);
              v8 = v20;
            }
          }
        }
        if ( !v9 )
          break;
        v12 = v8;
        v13 = *v8;
        if ( v13 >= 0xFFFE || *v6 == 37 && v9 + v13 >= 0xFFFE )
          break;
        v14 = v8[1] + 1024;
        if ( v14 <= (int)v9 )
          v14 = v9;
        if ( (unsigned int)v14 >= 0xFFFE )
          v14 = 65534;
        v15 = ExAllocatePoolWithTag(1, v14, 1799447891);
        v16 = v15;
        if ( !v15 )
        {
          result = -1073741801;
          v4 = v18;
          goto LABEL_28;
        }
        v17 = *((_DWORD *)v12 + 1);
        if ( v17 )
        {
          memmove(v15, v17, *v12);
          if ( *v19 )
            ExFreePoolWithTag(*((_DWORD *)v12 + 1));
        }
        a2 = v19;
        v8 = v20;
        *((_DWORD *)v12 + 1) = v16;
        v12[1] = v14;
        *v19 = 1;
      }
      v4 = v18;
    }
    result = 0;
LABEL_28:
    *v4 = 0;
  }
  return result;
}
