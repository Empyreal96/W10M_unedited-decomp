// NtAlpcCreateSectionView 
 
int __fastcall NtAlpcCreateSectionView(int a1, int a2, unsigned int a3, int a4)
{
  int v5; // r10
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r3
  int v14; // r5
  int v15; // r10
  int v16; // r0
  int v17; // r8
  int v18; // r4
  unsigned int *v19; // r2
  unsigned int v20; // r1
  int v21; // r1
  unsigned int *v22; // r2
  unsigned int v23; // r1
  int v24; // r1
  unsigned int v25; // r1
  __int16 v26; // r3
  int v28; // [sp+Ch] [bp-3Ch] BYREF
  _DWORD v29[2]; // [sp+10h] [bp-38h] BYREF
  int v30; // [sp+18h] [bp-30h]
  int v31; // [sp+1Ch] [bp-2Ch]
  int v32; // [sp+20h] [bp-28h]
  int v33; // [sp+24h] [bp-24h]
  int varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  unsigned int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  varg_r2 = a3;
  v5 = a1;
  varg_r0 = a1;
  v6 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v6 & 0xFFFFFFC0) + 0x134);
  if ( a2 )
    goto LABEL_28;
  if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( (a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a3 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a3 = *(_BYTE *)a3;
    *(_BYTE *)(a3 + 12) = *(_BYTE *)(a3 + 12);
    a1 = *(_DWORD *)a3;
    v7 = *(_DWORD *)(a3 + 4);
    v8 = *(_DWORD *)(a3 + 8);
    v9 = *(_DWORD *)(a3 + 12);
    v30 = *(_DWORD *)a3;
    v31 = v7;
    v32 = v8;
    v33 = v9;
  }
  else
  {
    a1 = *(_DWORD *)a3;
    v10 = *(_DWORD *)(a3 + 4);
    v11 = *(_DWORD *)(a3 + 8);
    v12 = *(_DWORD *)(a3 + 12);
    v30 = *(_DWORD *)a3;
    v31 = v10;
    v32 = v11;
    v33 = v12;
  }
  if ( v30 || v32 )
  {
LABEL_28:
    v14 = -1073741811;
  }
  else
  {
    v13 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    a1 = ObReferenceObjectByHandle(v5, 1, AlpcPortObjectType, v13, v29);
    v14 = a1;
    if ( a1 >= 0 )
    {
      v15 = v29[0];
      v16 = AlpcReferenceBlobByHandle(*(_DWORD *)(v29[0] + 8) + 20, v31, AlpcSectionType);
      v17 = v16;
      v29[1] = v16;
      if ( v16 )
      {
        v14 = AlpcpCreateSectionView(v16, v15, 0, v33, &v28);
        if ( v14 >= 0 )
        {
          v18 = v28;
          *(_DWORD *)(a3 + 8) = *(_DWORD *)(v28 + 20);
          *(_DWORD *)(a3 + 12) = *(_DWORD *)(v18 + 24);
          __dmb(0xBu);
          v19 = (unsigned int *)(v18 - 12);
          do
          {
            v20 = __ldrex(v19);
            v21 = v20 - 1;
          }
          while ( __strex(v21, v19) );
          __dmb(0xBu);
          if ( v21 <= 0 )
          {
            if ( v21 )
              KeBugCheckEx(24, 0, v18, 33, v21);
            AlpcpDestroyBlob(v18);
          }
        }
        __dmb(0xBu);
        v22 = (unsigned int *)(v17 - 12);
        do
        {
          v23 = __ldrex(v22);
          v24 = v23 - 1;
        }
        while ( __strex(v24, v22) );
        __dmb(0xBu);
        if ( v24 <= 0 )
        {
          if ( v24 )
            KeBugCheckEx(24, 0, v17, 33, v24);
          AlpcpDestroyBlob(v17);
        }
      }
      else
      {
        v14 = -1073741816;
      }
      a1 = ObfDereferenceObject(v15);
    }
  }
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = *(_WORD *)(v25 + 0x134) + 1;
  *(_WORD *)(v25 + 308) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
    KiCheckForKernelApcDelivery(a1);
  return v14;
}
