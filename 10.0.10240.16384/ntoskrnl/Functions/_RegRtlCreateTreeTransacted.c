// _RegRtlCreateTreeTransacted 
 
int __fastcall RegRtlCreateTreeTransacted(int a1, unsigned __int16 *a2, int a3, int a4, int a5, char a6, _DWORD *a7, int a8, int a9)
{
  int v11; // r5
  int v13; // r4
  _WORD *v14; // r0
  unsigned int v15; // r6
  unsigned __int16 *v16; // r4
  int i; // r7
  unsigned __int16 *v18; // r8
  unsigned __int16 *v19; // r0
  int j; // r3
  int v21; // r1
  char v22; // r0
  char v23; // r2
  int v24; // r3
  int v25; // r5
  int v26; // [sp+18h] [bp-30h] BYREF
  int v27; // [sp+1Ch] [bp-2Ch]
  int v28; // [sp+20h] [bp-28h] BYREF
  int v29; // [sp+24h] [bp-24h]
  int v30; // [sp+28h] [bp-20h]

  v29 = a4;
  v30 = a1;
  v26 = 0;
  v27 = a3;
  v11 = RegRtlCreateKeyTransacted(a1, a2, a3, a4, a5, a6, (int)a7, a8, a9);
  if ( v11 == -1073741772 )
  {
    v11 = RtlUnalignedStringCchLengthW(a2, 0x7FFF, &v28);
    if ( v11 >= 0 )
    {
      v13 = v28 + 1;
      v14 = (_WORD *)ExAllocatePoolWithTag(1, 2 * (v28 + 1), 1279739218);
      v15 = (unsigned int)v14;
      if ( v14 )
      {
        v11 = RtlStringCchCopyExW(v14, v13, a2);
        if ( !v11 )
        {
          v16 = (unsigned __int16 *)v15;
          for ( i = a1; ; i = v26 )
          {
            v18 = v16;
            v19 = wcschr(v16, 92);
            v16 = v19;
            if ( !v19 )
              goto LABEL_19;
            *v19 = 0;
            v16 = v19 + 1;
            for ( j = v19[1]; j == 92; j = *v16 )
              ++v16;
            if ( !*v16 )
              v16 = 0;
            if ( v16 )
            {
              v21 = 0;
              v22 = 0;
              v23 = v27 & 0xFC;
              v24 = 4;
              v25 = 0;
            }
            else
            {
LABEL_19:
              v23 = v27;
              v24 = v29;
              v21 = a5;
              v22 = a6;
              v25 = a8;
            }
            v11 = RegRtlCreateKeyTransacted(i, v18, v23, v24, v21, v22, (int)&v26, v25, a9);
            if ( i != v30 )
              ZwClose();
            if ( v11 )
              break;
            if ( !v16 )
            {
              *a7 = v26;
              break;
            }
          }
        }
        ExFreePoolWithTag(v15);
      }
      else
      {
        v11 = -1073741801;
      }
    }
  }
  return v11;
}
