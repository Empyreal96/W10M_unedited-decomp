// IopSymlinkRememberJunction 
 
int __fastcall IopSymlinkRememberJunction(unsigned int a1, int a2, int a3, unsigned __int16 *a4)
{
  int v4; // r8
  int v7; // r10
  int i; // r6
  int result; // r0
  __int16 v10; // r3
  int v11; // r0
  int v12; // r5
  unsigned int v13; // r4
  int v14; // r1
  int v15; // r0
  int v16; // r3
  __int16 v17; // r2
  int v18; // r2
  int v19; // r3
  int v20; // r4
  __int16 v21; // [sp+8h] [bp-38h] BYREF
  int v22; // [sp+Ch] [bp-34h] BYREF
  int v23; // [sp+10h] [bp-30h]
  unsigned __int16 v24[2]; // [sp+18h] [bp-28h] BYREF
  unsigned int v25; // [sp+1Ch] [bp-24h]

  v4 = (int)a4;
  v23 = a3;
  v7 = 0;
  i = (int)a4;
  if ( a4 )
  {
    if ( (a4[1] & 1) != 0 && *a4 <= a1 )
      return sub_7F9FF8();
    if ( (a4[1] & 1) == 0 )
      goto LABEL_14;
  }
  if ( a4 )
  {
    *a4 = a1;
    IopSymlinkFreeRelatedMountPointChain(a4);
  }
  else
  {
LABEL_14:
    v16 = *((_DWORD *)a4 + 2);
    for ( i = v4; v16; v16 = *(_DWORD *)(v16 + 8) )
      i = v16;
    v10 = *(_WORD *)(i + 2);
    v22 = i;
    *(_WORD *)(i + 2) = v10 | 1;
    *(_WORD *)i = a1;
    if ( v4 == i )
    {
      if ( *(_DWORD *)(a2 + 32) )
      {
        v17 = *(_WORD *)(v4 + 12);
        v24[0] = 0;
        v24[1] = 0;
        v25 = 0;
        v21 = 0;
        v7 = IopGetRelatedFileName(a2, v24, (unsigned __int16)(v17 + 2), &v21);
        if ( v7 >= 0 )
        {
          RtlAppendUnicodeToString(v24, (int)L"\\", v18, v19);
          RtlAppendUnicodeStringToString(v24, (unsigned __int16 *)(v4 + 12));
          v20 = v23;
          v7 = IopSymlinkUpdateECP(v23, v4, a1, v24, v21, *(_WORD *)(v4 + 2));
          ExFreePoolWithTag(v25);
          if ( v7 < 0 )
            return v7;
          IopSymlinkGetECP(*(_DWORD *)(v20 + 60), (int)&v22);
          i = v22;
        }
      }
    }
  }
  v11 = ExAllocatePoolWithTag(1, *(unsigned __int16 *)(a2 + 48) + 20, 1767075657);
  v12 = v11;
  *(_DWORD *)(i + 8) = v11;
  if ( !v11 )
    return -1073741670;
  v13 = *(unsigned __int16 *)(a2 + 48);
  v14 = *(_DWORD *)(a2 + 52);
  *(_WORD *)(v11 + 14) = *(_WORD *)(a2 + 48);
  v15 = v11 + 20;
  *(_WORD *)(v12 + 6) = 0;
  *(_WORD *)(v12 + 4) = 0;
  *(_WORD *)(v12 + 12) = 0;
  *(_DWORD *)(v12 + 16) = v15;
  *(_WORD *)v12 = 0;
  *(_WORD *)(v12 + 2) = 0;
  *(_DWORD *)(v12 + 8) = 0;
  memmove(v15, v14, v13);
  result = v7;
  *(_WORD *)(v12 + 12) += v13;
  return result;
}
