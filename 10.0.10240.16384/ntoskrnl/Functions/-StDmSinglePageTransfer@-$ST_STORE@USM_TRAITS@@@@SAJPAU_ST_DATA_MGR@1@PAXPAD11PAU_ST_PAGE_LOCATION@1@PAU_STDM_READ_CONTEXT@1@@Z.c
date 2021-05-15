// -StDmSinglePageTransfer@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAXPAD11PAU_ST_PAGE_LOCATION@1@PAU_STDM_READ_CONTEXT@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmSinglePageTransfer(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // r8
  int v8; // r7
  int v11; // r6
  BOOL v12; // r4
  int v13; // r5
  int result; // r0
  int v15; // r0
  int v16; // r4
  int v17; // r3
  unsigned int *v18; // r1
  unsigned int v19; // r4
  int v20[8]; // [sp+8h] [bp-20h] BYREF

  v20[0] = a4;
  v7 = a3;
  v8 = 0;
  if ( !a4 || (a4 & 1) != 0 )
  {
    v12 = 0;
    v13 = 0;
    v11 = 0;
    if ( (a4 & 1) == 0 )
      goto LABEL_10;
    v7 = a3 | 2;
  }
  else
  {
    v11 = a4;
    v12 = *(unsigned __int8 *)(a1 + 72) == 1;
    v13 = 1;
  }
  if ( v12 )
  {
    if ( !SmWdWorkItemMarkBusy(v11, 1, 1) )
      return -1073741431;
    v8 = 1;
  }
LABEL_10:
  v15 = a5;
  v16 = 0;
  if ( v13 )
  {
    v15 = SmMapPage(a5, v20);
    if ( (*(_DWORD *)(v11 + 4) & 0x8000000) != 0 )
      v16 = 1;
  }
  else
  {
    v20[0] = 4096;
  }
  if ( v15 )
  {
    v17 = v15 + (*(unsigned __int16 *)(a6 + 6) << 12);
    if ( v16 )
      v17 |= 1u;
    result = ST_STORE<SM_TRAITS>::StDmSinglePageCopy(a1, a2, v7, v17, a6, a7);
  }
  else
  {
    result = -1073741670;
  }
  if ( v8 )
  {
    v18 = (unsigned int *)(v11 + 4);
    __dmb(0xBu);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0xFFFDFFFF, v18) );
    __dmb(0xBu);
  }
  return result;
}
