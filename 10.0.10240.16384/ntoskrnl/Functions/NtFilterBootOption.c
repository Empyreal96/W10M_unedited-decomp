// NtFilterBootOption 
 
int __fastcall NtFilterBootOption(int a1, int a2, int a3, int a4, unsigned int a5)
{
  _DWORD *v5; // r6
  unsigned int v8; // r8
  int v9; // r2
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r5
  int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r10
  _DWORD *v16; // r0
  __int16 v17; // r3
  int v18; // r0
  int v19; // r0
  unsigned int v20; // r2
  unsigned int v21; // r2
  char v23[4]; // [sp+0h] [bp-48h] BYREF
  int v24; // [sp+4h] [bp-44h]
  int v25; // [sp+8h] [bp-40h]
  int v26; // [sp+Ch] [bp-3Ch]
  int v27; // [sp+10h] [bp-38h]
  int v28; // [sp+14h] [bp-34h]
  int v29; // [sp+18h] [bp-30h]
  _DWORD _20[15]; // [sp+20h] [bp-28h] BYREF
  _DWORD *varg_r3; // [sp+5Ch] [bp+14h]

  v5 = (_DWORD *)a4;
  varg_r3 = (_DWORD *)a4;
  _20[14] = a3;
  v24 = a2;
  _20[13] = a2;
  v27 = a1;
  _20[12] = a1;
  v8 = 0;
  v25 = 0;
  v9 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v10 = SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v9, a4);
  v23[0] = v10;
  if ( v10 || RtlCheckTokenMembership(0, SeAliasAdminsSid, (int)v23) >= 0 && v23[0] )
    v11 = 0;
  else
    v11 = -1073741790;
  if ( v11 < 0 )
    goto LABEL_62;
  if ( !dword_641874 )
  {
    v11 = -2143092730;
    goto LABEL_62;
  }
  if ( !a1 )
  {
    if ( !v24 && !a3 && !v5 && !a5 )
    {
      __dmb(0xBu);
      do
        v20 = __ldrex(&dword_649EF0);
      while ( !v20 && __strex(0, &dword_649EF0) );
      __dmb(0xBu);
      if ( !v20 )
      {
        v11 = SepSecureBootCorrectBcd();
        if ( v11 >= 0 )
        {
          __dmb(0xBu);
          do
            v21 = __ldrex(&dword_649EF0);
          while ( __strex(1u, &dword_649EF0) );
          __dmb(0xBu);
        }
      }
      goto LABEL_62;
    }
    goto LABEL_61;
  }
  if ( a1 == 1 )
  {
    if ( v24 )
    {
      if ( a3 )
      {
        if ( v5 )
        {
          v12 = a5;
          if ( a5 )
          {
            if ( ((1 << (HIBYTE(a3) & 0xF)) & dword_64A564) == 0 )
            {
LABEL_24:
              v11 = 0;
              goto LABEL_62;
            }
            if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
            {
              if ( (unsigned int)v5 + a5 > MmUserProbeAddress || (_DWORD *)((char *)v5 + a5) < v5 )
                *(_BYTE *)MmUserProbeAddress = 0;
              if ( a5 > 8 )
              {
                v13 = ExAllocatePoolWithTag(1, a5, 1649632595);
                v8 = v13;
                v25 = v13;
                if ( !v13 )
                {
                  v11 = -1073741801;
                  v28 = -1073741801;
                  goto LABEL_62;
                }
                memmove(v13, (int)v5, a5);
                v5 = (_DWORD *)v8;
                varg_r3 = (_DWORD *)v8;
              }
              else
              {
                memmove((int)_20, (int)v5, a5);
                v5 = _20;
                varg_r3 = _20;
              }
            }
            goto LABEL_34;
          }
        }
      }
    }
LABEL_61:
    v11 = -1073741811;
    goto LABEL_62;
  }
  if ( a1 != 2 )
  {
    v11 = -1073741585;
    goto LABEL_62;
  }
  if ( !v24 )
    goto LABEL_61;
  if ( !a3 )
    goto LABEL_61;
  if ( v5 )
    goto LABEL_61;
  v12 = a5;
  if ( a5 )
    goto LABEL_61;
  if ( ((1 << (HIBYTE(a3) & 0xF)) & dword_64A564) == 0 )
    goto LABEL_24;
LABEL_34:
  v14 = 0;
  v15 = *(unsigned __int16 *)(dword_641874 + 36);
  if ( *(_WORD *)(dword_641874 + 36) )
  {
    v26 = dword_6534DC;
    v16 = (_DWORD *)dword_6534DC;
    v29 = dword_64185C;
    while ( 1 )
    {
      if ( v16[1] == a3 && (!*v16 || *v16 == v24) )
      {
        v17 = *(_WORD *)(v16[2] + v29);
        if ( ((v17 & 0x20) == 0 || (dword_641868 & 4) != 0) && ((v17 & 0x40) == 0 || (dword_641868 & 0x10) != 0) )
          break;
      }
      ++v14;
      v16 += 3;
      if ( v14 >= v15 )
        goto LABEL_62;
    }
    v18 = v26 + 12 * v14;
    if ( v27 == 1 )
      v19 = SepSecureBootValidateBcdDataAgainstBcdRule(v18, v5, v12);
    else
      v19 = SepSecureBootFilterBootOptionDelete(v18);
    v11 = v19;
  }
LABEL_62:
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v11;
}
