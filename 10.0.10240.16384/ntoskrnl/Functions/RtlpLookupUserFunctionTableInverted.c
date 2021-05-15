// RtlpLookupUserFunctionTableInverted 
 
unsigned int __fastcall RtlpLookupUserFunctionTableInverted(unsigned int a1, unsigned int *a2)
{
  unsigned int *v2; // r5
  unsigned int v3; // r2
  unsigned int *v4; // r2
  int v5; // r1
  int v6; // r9
  int v7; // r8
  unsigned int v8; // r10
  unsigned int v9; // r3
  unsigned int result; // r0
  unsigned int v11; // r4
  unsigned int v12; // r3
  unsigned int v13; // r3
  _BYTE *v14; // r1
  unsigned int v15; // r0
  int v16; // [sp+0h] [bp-28h]

  v2 = a2;
  v16 = *((_DWORD *)KeUserInvertedFunctionTable + 2);
  __dmb(0xBu);
  v3 = *((_DWORD *)KeUserInvertedFunctionTable + 5);
  if ( a1 < v3 || a1 >= *((_DWORD *)KeUserInvertedFunctionTable + 6) + v3 )
  {
    v5 = *(_DWORD *)KeUserInvertedFunctionTable - 1;
    if ( (unsigned int)v5 > 0x200 )
      return 0;
    if ( *(_DWORD *)KeUserInvertedFunctionTable != 1 )
    {
      v6 = 1;
      while ( v5 >= v6 )
      {
        v7 = (v5 + v6) >> 1;
        v4 = (unsigned int *)((char *)KeUserInvertedFunctionTable + 16 * v7 + 16);
        v8 = v4[1];
        v9 = v4[2] + v8;
        if ( v9 < v8 )
          return 0;
        if ( a1 >= v8 )
        {
          if ( a1 < v9 )
            goto LABEL_15;
          v6 = v7 + 1;
        }
        else
        {
          if ( !v7 )
            break;
          v5 = v7 - 1;
        }
      }
    }
    v4 = 0;
  }
  else
  {
    v4 = (unsigned int *)((char *)KeUserInvertedFunctionTable + 16);
  }
LABEL_15:
  if ( !v4 )
    return 0;
  v11 = *v4;
  *v2 = *v4;
  v2[1] = v4[1];
  v2[3] = v4[3];
  v2[2] = v4[2];
  v12 = v2[3];
  if ( v12 )
  {
    if ( (v11 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v13 = v12 + v11;
    v14 = (_BYTE *)MmUserProbeAddress;
    if ( v13 > MmUserProbeAddress || v13 < v11 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v14 = (_BYTE *)MmUserProbeAddress;
    }
  }
  else
  {
    v14 = (_BYTE *)MmUserProbeAddress;
  }
  v15 = v2[1];
  if ( (_WORD)v15 )
    ExRaiseDatatypeMisalignment(v15);
  if ( v15 + 64 > (unsigned int)v14 || v15 + 64 < v15 )
    *v14 = 0;
  __dmb(0xFu);
  if ( *((_DWORD *)KeUserInvertedFunctionTable + 2) == v16 && (v16 & 1) == 0 )
    result = v11;
  else
    result = 0;
  return result;
}
