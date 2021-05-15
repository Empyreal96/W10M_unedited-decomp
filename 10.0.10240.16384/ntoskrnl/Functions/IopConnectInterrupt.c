// IopConnectInterrupt 
 
int __fastcall IopConnectInterrupt(unsigned int *a1, int a2, int a3, int a4, int a5, int a6, char a7, char a8, int a9, int a10)
{
  int v11; // r1
  int v12; // r4
  int v13; // r5
  int v14; // r6
  int v15; // r2
  int v16; // r9
  int v17; // r3
  int v18; // r3
  int v20; // r4
  _BYTE *v21; // r0
  unsigned int v22; // r5
  int v23; // r2
  int v24; // r3
  int v25; // r2
  unsigned int v26; // r4
  int v27; // r4
  int v28; // r3
  int v29; // r8
  _BYTE *v30; // r0
  int v31; // r10
  char v32; // r2
  int v33; // r10
  char v34; // r3
  int v35; // r7
  int i; // r6
  _DWORD *v37; // r0
  int v38; // [sp+24h] [bp-94h]
  int v39; // [sp+30h] [bp-88h]
  int v40; // [sp+38h] [bp-80h] BYREF
  int v41; // [sp+3Ch] [bp-7Ch]
  int v42; // [sp+40h] [bp-78h]
  int v43; // [sp+44h] [bp-74h]
  int v44; // [sp+48h] [bp-70h]
  int v45; // [sp+4Ch] [bp-6Ch]
  int v46; // [sp+50h] [bp-68h]
  int v47; // [sp+54h] [bp-64h]
  int v48; // [sp+58h] [bp-60h]
  unsigned int *v49; // [sp+5Ch] [bp-5Ch]
  int v50; // [sp+60h] [bp-58h]
  int v51; // [sp+64h] [bp-54h]
  int v52; // [sp+68h] [bp-50h]
  char v53[72]; // [sp+70h] [bp-48h] BYREF

  v50 = a3;
  v51 = a4;
  *a1 = 0;
  v52 = a2;
  v49 = a1;
  v46 = 0;
  v47 = 0;
  IopInitializeActiveConnectBlock(a10, v53);
  v11 = *(_DWORD *)(a10 + 24);
  v12 = *(_DWORD *)(a10 + 28);
  v13 = *(_DWORD *)(a10 + 32);
  v14 = *(_DWORD *)(a10 + 36);
  v45 = *(_DWORD *)(a10 + 12);
  v39 = v11;
  v40 = v12;
  v41 = v13;
  v42 = v14;
  v15 = dword_681D78[(unsigned __int16)v13];
  __dmb(0xBu);
  v16 = v15 & v40;
  v17 = *(unsigned __int8 *)(a10 + 16);
  v40 &= v15;
  v48 = v17;
  if ( !*(_DWORD *)(a10 + 8) && !off_617A68(0, *(_DWORD *)(a10 + 56)) )
  {
    v18 = *(_DWORD *)(a10 + 20);
    if ( v18 == 3 || v18 == 4 )
      return sub_7DEEF8();
  }
  v33 = (unsigned __int16)v41;
  if ( (unsigned __int16)v41 < (unsigned int)KeQueryActiveGroupCount()
    && v16
    && (dword_681D78[(unsigned __int16)v13] & v16) == v16
    && !(HIWORD(v42) | (unsigned __int16)v42 | HIWORD(v41))
    && (v34 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v16 >> 16))
            + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v16 >> 24))
            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v16 >> 8))
            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v16),
        (v35 = v34) != 0) )
  {
    v20 = v34 + 79;
    v21 = (_BYTE *)ExAllocatePoolWithTag(512, 4 * v20, 1852403529);
    v22 = (unsigned int)v21;
    if ( v21 )
    {
      memset(v21, 0, 4 * v20);
      KeInitializeDpc(v22 + 284, 0, 0);
      memmove(v22 + 8, a10, 0x50u);
      *(_DWORD *)(v22 + 32) = v39;
      v23 = v41;
      v24 = v42;
      *(_DWORD *)(v22 + 36) = v40;
      *(_DWORD *)(v22 + 40) = v23;
      *(_DWORD *)(v22 + 44) = v24;
      v43 = a6;
      if ( !a6 )
        v43 = v22;
      *(_BYTE *)(v22 + 264) = a7 == 0;
      if ( !a7 )
        v47 = v22 + 268;
      v25 = 0;
      v26 = 0;
      v44 = 0;
      for ( *(_DWORD *)(v22 + 4) = v16; v25 < v35; v26 = (unsigned __int8)(v26 + 1) )
      {
        if ( ((1 << v26) & v16) != 0 )
        {
          if ( v33 || v26 >= KeNumberProcessors_0 )
            v29 = -1;
          else
            v29 = v26;
          v30 = (_BYTE *)KeAllocateInterrupt((int)*(&KiProcessorBlock + v29));
          v31 = (int)v30;
          if ( !v30 )
          {
            v27 = -1073741670;
            goto LABEL_35;
          }
          memset(v30, 0, 176);
          KeInitializeInterruptEx(v31, v52, v50, v51, a5, v43, v47, v45, v48, a7, v39, a8, v29, v38, v46, v22 + 8);
          v32 = v44;
          *(_DWORD *)(v22 + 4 * v44 + 316) = v31;
          v25 = (char)(v32 + 1);
          v33 = (unsigned __int16)v41;
          v44 = v25;
        }
      }
      if ( !a7 )
      {
        v27 = IopAllocatePassiveInterruptBlock(v22 + 8, &v40);
        if ( v27 < 0 )
          goto LABEL_35;
      }
      IopAcquireActiveConnectLock(v53);
      v27 = KeConnectInterrupt(v22 + 316, (unsigned __int8)v35, v22 + 8, v28);
      IopReleaseActiveConnectLock(v53);
      if ( v27 < 0 )
      {
        if ( !a7 )
          IopDestroyPassiveInterruptBlock(v45);
      }
      else
      {
        memmove(v22 + 88, *(_DWORD *)(v22 + 316), 0xB0u);
        v27 = 0;
        *v49 = v22;
      }
      if ( v27 < 0 )
      {
LABEL_35:
        if ( v35 > 0 )
        {
          for ( i = 0; i < v35; i = (char)(i + 1) )
          {
            v37 = *(_DWORD **)(v22 + 4 * i + 316);
            if ( v37 )
              KeFreeInterrupt(v37);
          }
        }
        ExFreePoolWithTag(v22);
      }
    }
    else
    {
      v27 = -1073741670;
    }
  }
  else
  {
    v27 = -1073741811;
  }
  IopDestroyActiveConnectBlock(v53);
  return v27;
}
