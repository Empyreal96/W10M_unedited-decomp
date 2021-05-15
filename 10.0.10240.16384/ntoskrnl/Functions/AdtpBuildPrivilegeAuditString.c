// AdtpBuildPrivilegeAuditString 
 
int __fastcall AdtpBuildPrivilegeAuditString(unsigned int *a1, unsigned int a2, int a3, int a4, unsigned int *a5, _BYTE *a6)
{
  int v6; // r5
  _DWORD *v8; // r8
  __int64 v10; // r2
  int v12; // r3
  __int16 v13; // r4
  unsigned int v14; // r0
  int v15; // r7
  _WORD *v16; // r6
  unsigned int v17; // r10
  __int64 *v18; // r4
  unsigned int v19; // r8
  unsigned int v20; // r5
  int v21; // r4
  __int64 *v22; // [sp+0h] [bp-50h]
  _DWORD *v24; // [sp+8h] [bp-48h]
  int v25; // [sp+10h] [bp-40h]
  unsigned __int16 v26; // [sp+18h] [bp-38h] BYREF
  int v27; // [sp+1Ch] [bp-34h]
  _DWORD v28[2]; // [sp+20h] [bp-30h] BYREF
  unsigned __int16 v29; // [sp+28h] [bp-28h] BYREF
  int v30; // [sp+2Ch] [bp-24h]

  v6 = a3;
  v24 = (_DWORD *)a2;
  v8 = (_DWORD *)a2;
  if ( !*a1 )
  {
    if ( !a3 )
    {
      if ( a2 )
        RtlInitUnicodeString(a2, L"-");
      return 0;
    }
    v10 = 0x400000000i64;
    *(_DWORD *)v6 = dword_406F40;
    goto LABEL_4;
  }
  if ( *a1 > 0x41 )
    return -1073741811;
  RtlInitUnicodeString((unsigned int)&v26, L"\r\n\t\t\t");
  RtlInitUnicodeString((unsigned int)&v29, L"?");
  v12 = (unsigned __int16)((AdtpWellKnownPrivilegeMaxLen + v26) * *(_WORD *)a1 - v26 + 2) >> 1;
  if ( a4 )
  {
    v13 = (unsigned __int16)((AdtpWellKnownPrivilegeMaxLen + v26) * *(_WORD *)a1 - v26 + 2) >> 1;
    v14 = *a5 + v12;
    if ( v14 < 0x400 )
    {
      v15 = a4 + 2 * *a5;
      *a5 = v14;
LABEL_15:
      HIWORD(v25) = 2 * v13;
      v16 = (_WORD *)v15;
      v17 = 0;
      if ( *a1 )
      {
        v18 = (__int64 *)(a1 + 2);
        v19 = v29;
        v20 = v26;
        v22 = (__int64 *)(a1 + 2);
        do
        {
          if ( AdtpLookupKnownPrivilegeNameQuickly(v18, v28) )
          {
            memmove((int)v16, v30, v19);
            v16 = (_WORD *)((char *)v16 + v19);
          }
          else
          {
            v21 = LOWORD(v28[0]);
            memmove((int)v16, v28[1], LOWORD(v28[0]));
            v16 = (_WORD *)((char *)v16 + v21);
            v18 = v22;
          }
          if ( v17 < *a1 - 1 )
          {
            memmove((int)v16, v27, v20);
            v16 = (_WORD *)((char *)v16 + v20);
          }
          ++v17;
          v18 = (__int64 *)((char *)v18 + 12);
          v22 = v18;
        }
        while ( v17 < *a1 );
        v6 = a3;
        v8 = v24;
      }
      LODWORD(v10) = 0;
      *v16 = 0;
      if ( !v6 )
      {
        LOWORD(v25) = (_WORD)v16 - v15;
        *v8 = v25;
        v8[1] = v15;
        return 0;
      }
      *(_DWORD *)v6 = v15;
      HIDWORD(v10) = (unsigned __int16)((_WORD)v16 - v15) + 2;
LABEL_4:
      *(_QWORD *)(v6 + 4) = v10;
      *(_DWORD *)(v6 + 12) = v10;
      return 0;
    }
  }
  v13 = (unsigned __int16)((AdtpWellKnownPrivilegeMaxLen + v26) * *(_WORD *)a1 - v26 + 2) >> 1;
  v15 = ExAllocatePoolWithTag(1, 2 * v12, 1799447891);
  if ( v15 )
  {
    *a6 = 1;
    goto LABEL_15;
  }
  return -1073741801;
}
