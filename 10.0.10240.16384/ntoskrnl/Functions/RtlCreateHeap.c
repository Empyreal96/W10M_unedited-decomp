// RtlCreateHeap 
 
int __fastcall RtlCreateHeap(int a1, _BYTE *a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v7; // r5
  int v8; // r9
  int v9; // r6
  _DWORD *v10; // r10
  int v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r2
  _DWORD *v14; // r3
  int v15; // r4
  unsigned int v16; // r6
  _BYTE *v17; // r2
  unsigned int v18; // r1
  _BYTE *v19; // r1
  int v20; // r4
  int v21; // r2
  int v22; // r0
  char v23; // r3
  int v25; // [sp+10h] [bp-100h]
  unsigned int v26; // [sp+18h] [bp-F8h]
  int v27; // [sp+18h] [bp-F8h]
  unsigned int v28; // [sp+1Ch] [bp-F4h]
  int v29; // [sp+20h] [bp-F0h]
  unsigned int v30; // [sp+20h] [bp-F0h]
  int v33; // [sp+28h] [bp-E8h]
  int v34; // [sp+2Ch] [bp-E4h]
  int v35; // [sp+30h] [bp-E0h]
  int v36; // [sp+34h] [bp-DCh]
  int v37; // [sp+38h] [bp-D8h]
  unsigned int v38; // [sp+3Ch] [bp-D4h]
  unsigned int v39; // [sp+40h] [bp-D0h]
  int v40; // [sp+44h] [bp-CCh]
  int v41; // [sp+48h] [bp-C8h]
  int v42; // [sp+4Ch] [bp-C4h]
  int v43; // [sp+50h] [bp-C0h]
  _BYTE *v44; // [sp+58h] [bp-B8h]
  unsigned int v45; // [sp+64h] [bp-ACh]
  int v46; // [sp+68h] [bp-A8h]
  char v47; // [sp+6Ch] [bp-A4h]
  int v48; // [sp+84h] [bp-8Ch]
  _DWORD v49[20]; // [sp+90h] [bp-80h] BYREF
  int v50; // [sp+E0h] [bp-30h]
  int varg_r0; // [sp+118h] [bp+8h]
  _BYTE *varg_r1; // [sp+11Ch] [bp+Ch]
  int varg_r2; // [sp+120h] [bp+10h]
  int varg_r3; // [sp+124h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v7 = a1;
  v8 = NtGlobalFlag;
  v37 = 0;
  v9 = 0;
  v25 = 0;
  v10 = 0;
  if ( (a1 & 0x10000000) == 0 )
  {
    if ( RtlpHeapErrorHandlerThreshold >= 2 && (a1 & 0xFFF80F00) != 0 )
    {
      DbgPrint("!(CheckedFlags & ~HEAP_CREATE_VALID_MASK)");
      RtlpHeapHandleError();
    }
    if ( (a1 & 0xFFF80F00) != 0 )
      v7 = a1 & 0x7F0FF;
  }
  memset(v49, 0, 48);
  if ( a6 && *a6 == 48 )
    memmove((int)v49, (int)a6, 0x30u);
  if ( (v8 & 0x10) != 0 )
    v7 |= 0x20u;
  if ( (v8 & 0x20) != 0 )
    v7 |= 0x40u;
  if ( (v8 & 0x200000) != 0 )
    v7 |= 0x80u;
  v43 = v49[1];
  if ( !v49[1] )
    v43 = dword_681290;
  v40 = v49[2];
  if ( !v49[2] )
    v40 = dword_68128C;
  v38 = v49[3];
  if ( !v49[3] )
    v38 = dword_681284;
  v39 = v49[4];
  if ( !v49[4] )
    v39 = dword_681288;
  v11 = dword_64177C;
  if ( !dword_64177C )
  {
    v9 = 0;
    if ( ZwQuerySystemInformation() < 0 )
    {
LABEL_105:
      v15 = 0;
LABEL_106:
      v14 = a5;
      goto LABEL_107;
    }
    v11 = v50;
    dword_64177C = v50;
  }
  v41 = v49[5];
  if ( !v49[5] )
    v41 = v11 - 69632;
  v35 = v49[6];
  if ( !v49[6] || v49[6] > 0x7F000u )
    v35 = 520192;
  if ( a4 )
  {
    v12 = (a4 + 4095) & 0xFFFFF000;
    v28 = v12;
  }
  else
  {
    v12 = 4096;
    v28 = 4096;
  }
  if ( a3 )
    v13 = (a3 + 4095) & 0xFFFFF000;
  else
    v13 = (v12 + 0xFFFF) & 0xFFFF0000;
  v26 = v13;
  if ( v12 > v13 )
  {
    v12 = v13;
    v28 = v13;
  }
  if ( (v7 & 2) == 0 || a2 )
  {
    v42 = 0;
  }
  else
  {
    v42 = 4096;
    v37 = 2;
    if ( v13 - 4096 < v12 )
    {
      v13 = (v13 + 69631) & 0xFFFF0000;
      v26 = v13;
    }
  }
  if ( !v12 || !v13 )
    goto LABEL_105;
  v29 = 584;
  v14 = a5;
  if ( (v7 & 1) == 0 )
  {
    if ( a5 )
    {
      v7 |= 0x80000000;
      v10 = a5;
    }
    else
    {
      v29 = 640;
    }
LABEL_53:
    if ( a2 )
    {
      if ( v49[9] )
      {
        if ( !v49[7] || !v49[8] || v49[7] > v49[8] || (v7 & 2) != 0 )
          goto LABEL_105;
        v34 = (int)a2;
        v16 = (unsigned int)&a2[v49[7]];
        v27 = v49[8];
        memset(a2, 0, 4096);
        v17 = a2;
      }
      else
      {
        if ( ZwQueryVirtualMemory() < 0 )
          goto LABEL_61;
        v16 = (unsigned int)v44;
        if ( v44 != a2 || v46 == 0x10000 )
          goto LABEL_61;
        v17 = v44;
        v34 = (int)v44;
        if ( v46 == 4096 )
        {
          if ( (v7 & 0x40000) != 0 && (v47 & 0x40) == 0 )
            goto LABEL_61;
          memset(v44, 0, 4096);
          if ( ZwQueryVirtualMemory() < 0 )
            goto LABEL_61;
          v27 = v48;
          v28 = v45;
          v17 = v44;
          v16 = (unsigned int)&v44[v45];
        }
        else
        {
          v27 = v45;
          v18 = v28;
          if ( v28 > v45 )
          {
            v18 = v45;
            v28 = v45;
          }
          if ( v18 < 0x1000 )
            goto LABEL_61;
        }
      }
      v37 |= 1u;
      v19 = a2;
      v25 = (int)a2;
    }
    else
    {
      if ( v49[9] )
        goto LABEL_105;
      v36 = (RtlpHeapGenerateRandomValue64() & 0x1F) << 16;
      v33 = v36 + v26;
      if ( v36 + v26 < v26 )
      {
        v33 = v26;
        v36 = 0;
      }
      if ( ZwAllocateVirtualMemory() < 0 )
        goto LABEL_61;
      v19 = 0;
      v25 = 0;
      v27 = v33;
      if ( v36 )
      {
        ZwFreeVirtualMemory();
        v19 = (_BYTE *)v36;
        v25 = v36;
        v27 = v33 - v36;
      }
      v17 = v19;
      v34 = (int)v19;
      v16 = (unsigned int)v19;
    }
    if ( v17 == (_BYTE *)v16 )
    {
      if ( ZwAllocateVirtualMemory() < 0 )
      {
LABEL_61:
        v9 = v25;
        goto LABEL_105;
      }
      if ( (dword_682608 & 0x20) != 0 )
        RtlpLogHeapCommit(v25, v34, v28, 1);
      v16 += v28;
      v19 = (_BYTE *)v25;
    }
    v20 = (int)(v19 + 584);
    if ( (NtGlobalFlag & 0x800) != 0 )
    {
      *((_DWORD *)v19 + 47) = (unsigned int)(v19 + 591) & 0xFFFFFFF8;
      v29 += 1548;
      v19 = (_BYTE *)v25;
      v20 = *(_DWORD *)(v25 + 188) + 1548;
      v7 |= 0x4000000u;
    }
    v30 = (v29 + 7) & 0xFFFFFFF8;
    *(_WORD *)v19 = v30 >> 3;
    *(_BYTE *)(v25 + 2) = 1;
    *(_BYTE *)(v25 + 7) = 1;
    *(_DWORD *)(v25 + 96) = -285217025;
    *(_DWORD *)(v25 + 64) = v7 & 0xEFFFFFFF;
    *(_DWORD *)(v25 + 88) = 0;
    memset((_BYTE *)(v25 + 480), 0, 92);
    RtlpCreateHeapEncoding(v25);
    *(_DWORD *)(v25 + 68) = v7 & 0x6001007D;
    *(_WORD *)(v25 + 126) = v20 - v25;
    *(_DWORD *)(v25 + 128) = 0;
    *(_DWORD *)(v25 + 196) = v25 + 192;
    *(_DWORD *)(v25 + 192) = v25 + 192;
    *(_DWORD *)(v25 + 160) = v25 + 156;
    *(_DWORD *)(v25 + 156) = v25 + 156;
    *(_DWORD *)(v25 + 168) = v25 + 164;
    *(_DWORD *)(v25 + 164) = v25 + 164;
    *(_DWORD *)(v25 + 144) = v25 + 140;
    *(_DWORD *)(v25 + 140) = v25 + 140;
    if ( !v10 && (v7 & 1) == 0 )
    {
      v10 = (_DWORD *)v20;
      if ( ExInitializeResourceLite(v20) < 0 )
      {
        v10 = 0;
        goto LABEL_61;
      }
      v20 += 56;
    }
    *(_DWORD *)(v25 + 200) = v10;
    *(_DWORD *)(v25 + 72) |= 0x80000000;
    if ( RtlpInitializeHeapSegment(v25, v25, v30 + 568, v30, v37, v34, v16, v27 + v34 - v42) )
    {
      if ( a2 )
        memset((_BYTE *)v20, 0, 128);
      *(_DWORD *)(v20 + 4) = 128;
      *(_DWORD *)(v20 + 28) = v20 + 36;
      *(_DWORD *)(v20 + 24) = v25 + 192;
      *(_DWORD *)(v20 + 32) = v20 + 52;
      RtlpPopulateListIndex(v25, (_DWORD *)v20);
      *(_WORD *)(v25 + 124) = 0;
      *(_DWORD *)(v25 + 100) = v43;
      *(_DWORD *)(v25 + 104) = v40;
      *(_DWORD *)(v25 + 108) = v38 >> 3;
      *(_DWORD *)(v25 + 112) = v39 >> 3;
      *(_DWORD *)(v25 + 120) = v41;
      *(_DWORD *)(v25 + 92) = (unsigned int)(v35 + 7) >> 3;
      *(_DWORD *)(v25 + 204) = v49[9] ^ RtlpHeapKey;
      *(_DWORD *)(v25 + 572) = 4;
      *(_DWORD *)(v25 + 576) = 1040384;
      if ( (v7 & 0x10000) != 0 )
      {
        *(_DWORD *)(v25 + 148) = 23;
        v21 = -16;
      }
      else
      {
        *(_DWORD *)(v25 + 148) = 15;
        v21 = -8;
      }
      *(_DWORD *)(v25 + 152) = v21;
      v22 = v25;
      if ( (*(_DWORD *)(v25 + 64) & 0x20) != 0 )
      {
        *(_DWORD *)(v25 + 148) += 8;
        v22 = v25;
      }
      v23 = dword_682608;
      if ( (dword_682608 & 0x20) != 0 )
      {
        RtlpLogHeapCreateEvent(v22, v7, v27, v28);
        v22 = v25;
        v23 = dword_682608;
      }
      if ( (v23 & 0x20) != 0 )
      {
        RtlpHeapLogRangeCreate(v22, v27, v7);
        v22 = v25;
      }
      *(_DWORD *)(v22 + 72) &= 0x7FFFFFFFu;
      v15 = v25;
      v9 = 0;
      v25 = 0;
      v10 = 0;
      goto LABEL_106;
    }
    goto LABEL_61;
  }
  if ( !a5 )
    goto LABEL_53;
  v15 = 0;
LABEL_107:
  if ( v10 && v10 != v14 )
  {
    ExDeleteResourceLite(v10);
    v9 = v25;
  }
  if ( v9 && !a2 )
    ZwFreeVirtualMemory();
  return v15;
}
