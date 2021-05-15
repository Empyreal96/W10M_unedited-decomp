// PnpGetDeviceDependencyList 
 
int __fastcall PnpGetDeviceDependencyList(int a1, int a2, int a3, unsigned int a4, _DWORD *a5)
{
  int v5; // r6
  unsigned int v6; // r7
  _WORD *v7; // r9
  int v8; // r5
  int v9; // r4
  _DWORD **v10; // r0
  int v11; // r1
  int v12; // r2
  _DWORD *v13; // r10
  int v14; // r8
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r1
  int v19; // r6
  unsigned __int16 *v20; // r0
  unsigned __int16 *v21; // r6
  unsigned __int16 *v22; // r8
  unsigned int v24; // [sp+8h] [bp-40h] BYREF
  _WORD *v25; // [sp+Ch] [bp-3Ch] BYREF
  unsigned __int16 *v26; // [sp+10h] [bp-38h] BYREF
  unsigned int v27; // [sp+14h] [bp-34h] BYREF
  _DWORD **v28; // [sp+18h] [bp-30h]
  int v29; // [sp+1Ch] [bp-2Ch]
  unsigned __int16 *v30; // [sp+20h] [bp-28h]
  unsigned int v31; // [sp+24h] [bp-24h]
  int v32; // [sp+28h] [bp-20h]

  v5 = *(_DWORD *)(a1 + 16);
  v31 = a4;
  v32 = a3;
  v6 = a4;
  v24 = a4;
  v25 = (_WORD *)a3;
  v26 = 0;
  v29 = a2;
  v7 = (_WORD *)a3;
  v8 = 0;
  v9 = 0;
  PnpAcquireDependencyRelationsLock(0, a2);
  if ( v29 )
  {
    if ( v29 != 1 )
    {
      v9 = -1073741811;
      goto LABEL_37;
    }
    v10 = (_DWORD **)PiGetDependentList(v5);
  }
  else
  {
    v10 = (_DWORD **)PiGetProviderList(v5);
  }
  v13 = *v10;
  v14 = (int)v10;
  v28 = v10;
  if ( v13 != v10 )
  {
    do
    {
      v15 = PiListEntryToDependencyEdge((int)v13, v11);
      v13 = (_DWORD *)*v13;
      if ( v16 )
        v17 = *(_DWORD *)(v15 + 20);
      else
        v17 = *(_DWORD *)(v15 + 16);
      v18 = *(_DWORD *)(v17 + 24);
      if ( v18 )
        v19 = *(_DWORD *)(*(_DWORD *)(v18 + 176) + 20);
      else
        v19 = 0;
      if ( v18 && v19 && (v20 = *(unsigned __int16 **)(v19 + 24)) != 0 )
      {
        v9 = RtlStringCchLengthW(v20, 0xC8u, &v27);
        if ( v9 < 0 )
          goto LABEL_37;
        v8 += ++v27;
        if ( v27 <= v6 )
        {
          v9 = RtlStringCchCopyExW(v7, v6, *(_DWORD *)(v19 + 24), &v25, &v24, 2048);
          if ( v9 < 0 )
            goto LABEL_37;
          v7 = v25 + 1;
          v6 = --v24;
          ++v25;
        }
      }
      else
      {
        v21 = *(unsigned __int16 **)(v17 + 28);
        v30 = (unsigned __int16 *)(v17 + 28);
        if ( v21 != (unsigned __int16 *)(v17 + 28) )
        {
          while ( 1 )
          {
            v22 = v21;
            v21 = *(unsigned __int16 **)v21;
            v9 = PnpUnicodeStringToWstr((int *)&v26, 0, v22 + 4);
            if ( v9 < 0 )
              goto LABEL_37;
            v9 = RtlStringCchLengthW(v26, 0x7FFFu, &v27);
            if ( v9 < 0 )
              break;
            v8 += ++v27;
            if ( v27 <= v6 )
            {
              v9 = RtlStringCchCopyExW(v7, v6, v26, &v25, &v24, 2048);
              if ( v9 < 0 )
              {
                PnpUnicodeStringToWstrFree((unsigned int)v26, (int)(v22 + 4));
                v6 = v24;
                v7 = v25;
LABEL_29:
                v14 = (int)v28;
                goto LABEL_30;
              }
              v7 = v25 + 1;
              v6 = --v24;
              ++v25;
            }
            PnpUnicodeStringToWstrFree((unsigned int)v26, (int)(v22 + 4));
            if ( v21 == v30 )
              goto LABEL_29;
          }
          PnpUnicodeStringToWstrFree((unsigned int)v26, (int)(v22 + 4));
          goto LABEL_29;
        }
LABEL_30:
        if ( v9 < 0 )
          goto LABEL_37;
      }
      v11 = v29;
    }
    while ( v13 != (_DWORD *)v14 );
    v12 = -1073741789;
  }
  if ( ++v8 <= v31 )
    *(_WORD *)(v32 + 2 * v8 - 2) = 0;
  else
    v9 = v12;
LABEL_37:
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  if ( v9 >= 0 || v9 == -1073741789 )
  {
    if ( a5 )
      *a5 = v8;
  }
  return v9;
}
