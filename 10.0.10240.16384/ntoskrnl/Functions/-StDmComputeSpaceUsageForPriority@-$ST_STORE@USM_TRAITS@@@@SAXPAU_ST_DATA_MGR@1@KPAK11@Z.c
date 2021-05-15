// -StDmComputeSpaceUsageForPriority@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@KPAK11@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmComputeSpaceUsageForPriority(int result, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v5; // kr00_8
  int v8; // r4
  __int64 v9; // kr08_8
  unsigned int v10; // r3
  unsigned int v11; // r1
  int v12; // r5

  v5 = *(_QWORD *)(result + 8 * a2 + 684);
  if ( *(_BYTE *)(result + 72) )
    v8 = (_DWORD)v5 << *(_DWORD *)(result + 100);
  else
    v8 = *(_DWORD *)(result + 8 * a2 + 688);
  v9 = *(_QWORD *)(result + 104);
  v10 = (v9 - HIDWORD(v9) + 1) * v5;
  v11 = v10 - HIDWORD(v5);
  if ( v10 < HIDWORD(v5) || v11 < (unsigned int)v9 )
    goto LABEL_9;
  v12 = *(_DWORD *)(result + 12 * a2 + 392);
  if ( v12 != -1 )
    v11 = (*(_WORD *)(*(_DWORD *)(result + 304) + 2 * v12) & 0x1FFF) - v9 + HIDWORD(v9) + v11 - 1;
  if ( v11 < (unsigned int)v9 )
LABEL_9:
    v11 = 0;
  *a3 += v5;
  *a4 += v8;
  *a5 += v11;
  return result;
}
