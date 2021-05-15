// PfpFlushBuffers 
 
int PfpFlushBuffers()
{
  _DWORD *v0; // r9
  unsigned int v1; // r10
  _DWORD *v3; // r0
  _DWORD *v4; // r3
  int v5; // r8
  __int64 v6; // kr10_8
  __int64 v7; // kr18_8
  int v8; // r4
  int v9; // r6
  int v10; // r5
  int v11; // r3
  _DWORD *i; // r4
  _DWORD *v13; // r0
  int v14; // [sp+8h] [bp-50h]
  int v15; // [sp+Ch] [bp-4Ch]
  int v16; // [sp+10h] [bp-48h] BYREF
  int v17; // [sp+14h] [bp-44h]
  _DWORD v18[2]; // [sp+18h] [bp-40h] BYREF
  int v19[2]; // [sp+20h] [bp-38h] BYREF
  int v20; // [sp+28h] [bp-30h] BYREF
  int v21; // [sp+2Ch] [bp-2Ch]
  int v22; // [sp+30h] [bp-28h]
  int v23; // [sp+34h] [bp-24h]

  v18[0] = 0;
  v18[1] = 1;
  v0 = 0;
  v15 = 0;
  v1 = 0;
  v14 = PfpFlushEventBuffers();
  if ( v14 < 0 )
    return 0;
  v3 = (_DWORD *)RtlpInterlockedFlushSList((unsigned __int64 *)&unk_643B60);
  if ( !v3 )
    goto LABEL_32;
  do
  {
    v4 = v3;
    v3 = (_DWORD *)*v3;
    *v4 = v0;
    v0 = v4;
  }
  while ( v3 );
  while ( 1 )
  {
    v5 = (int)v0;
    v20 = 0;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v6 = *((_QWORD *)v0 + 2);
    v0 = (_DWORD *)*v0;
    v7 = *(_QWORD *)(v5 + 24);
    v21 = ((__int64)((((unsigned int)v6 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                   + ((HIDWORD(v6) * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
        + dword_63728C;
    v22 = v21;
    v23 = ((__int64)((((unsigned int)v7 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                   + ((HIDWORD(v7) * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
        + dword_63728C;
    v20 = 163851;
    PfpCopyEvent((int)&v20);
    if ( *(int *)(v5 + 4) > 1 )
      break;
    v19[0] = 94215;
    v19[1] = *(_DWORD *)(v5 + 8);
    PfpCopyEvent((int)v19);
    if ( *(int *)(v5 + 4) > 1 )
      break;
    v8 = *(_DWORD *)(v5 + 44);
    v9 = *(_DWORD *)(v5 + 40);
    if ( v8 == 1 )
    {
      v8 = *(_DWORD *)(v5 + 48) + 1;
LABEL_9:
      v10 = v5 + 56;
      v15 = v5 + 56;
      v1 = v5 + 56;
      if ( (unsigned int)(v5 + 56) >= *(_DWORD *)(v5 + 32) )
      {
LABEL_23:
        v11 = v14;
      }
      else
      {
        while ( PfpLogPageAccess(v8, v1, v18, v9, 0) )
        {
          v1 += 8;
          if ( v1 >= *(_DWORD *)(v5 + 32) )
            goto LABEL_23;
        }
        v11 = -1073741432;
        v14 = -1073741432;
      }
      goto LABEL_24;
    }
    if ( !v8 || *(_DWORD *)(v8 + 176) && *(_QWORD *)(v8 + 200) )
      goto LABEL_9;
    MmFreeAccessPfnBuffer(v5, 0);
LABEL_26:
    if ( !v0 )
      goto LABEL_32;
  }
  for ( i = *(_DWORD **)(v5 + 32); ; ++i )
  {
    if ( (unsigned int)i > *(_DWORD *)(v5 + 36) )
    {
      v10 = v15;
      goto LABEL_23;
    }
    v11 = PfpLogStandbyRepurpose(*i);
    v14 = v11;
    if ( v11 < 0 )
      break;
  }
  v10 = v15;
  *(_DWORD *)(v5 + 32) = i;
LABEL_24:
  if ( v11 >= 0 )
  {
    v16 = 0;
    v17 = 0;
    v17 = dword_63728C
        + ((__int64)(((*(unsigned int *)(v5 + 24) * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                   + ((*(unsigned int *)(v5 + 28) * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10);
    v16 = 147463;
    PfpCopyEvent((int)&v16);
    MmFreeAccessPfnBuffer(v5, 0);
    goto LABEL_26;
  }
  if ( *(int *)(v5 + 4) <= 1 )
  {
    memmove(v10, v1, 8 * ((int)(*(_DWORD *)(v5 + 32) - v1) >> 3));
    *(_DWORD *)(v5 + 32) -= 8 * ((int)(v1 - v10) >> 3);
  }
  PfpReturnAccessBuffer((_DWORD *)v5);
LABEL_32:
  if ( v14 < 0 )
  {
    while ( v0 )
    {
      v13 = v0;
      v0 = (_DWORD *)*v0;
      PfpReturnAccessBuffer(v13);
    }
    return 0;
  }
  return 1;
}
