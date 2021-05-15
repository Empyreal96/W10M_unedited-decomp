// NtQuerySecurityAttributesToken 
 
int __fastcall NtQuerySecurityAttributesToken(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v7; // lr
  unsigned int v8; // r6
  int v9; // r3
  int v10; // r5
  int v11; // r4
  int v12; // r8
  int v13; // r4
  int v14; // r6
  int v15; // r3
  int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  int v21; // [sp+8h] [bp-48h]
  int v22; // [sp+8h] [bp-48h]
  _BYTE v23[4]; // [sp+10h] [bp-40h] BYREF
  int v24; // [sp+14h] [bp-3Ch]
  unsigned int v25; // [sp+18h] [bp-38h] BYREF
  int v26; // [sp+1Ch] [bp-34h] BYREF
  int v27; // [sp+20h] [bp-30h]
  int v28; // [sp+24h] [bp-2Ch]
  int v29; // [sp+28h] [bp-28h]
  int v30; // [sp+2Ch] [bp-24h]
  _DWORD _30[14]; // [sp+30h] [bp-20h] BYREF

  _30[13] = a4;
  v7 = a3;
  v27 = a3;
  _30[12] = a3;
  v28 = a2;
  _30[11] = a2;
  v29 = a1;
  _30[10] = a1;
  v8 = 0;
  v25 = 0;
  v9 = 0;
  v24 = 0;
  v23[0] = 0;
  v10 = 0;
  v26 = 0;
  v11 = __mrc(15, 0, 13, 0, 3);
  v12 = *(char *)((v11 & 0xFFFFFFC0) + 0x15A);
  v23[1] = *(_BYTE *)((v11 & 0xFFFFFFC0) + 0x15A);
  if ( a5 )
  {
    if ( a4 )
      goto LABEL_6;
  }
  else if ( !a4 )
  {
LABEL_6:
    if ( v12 )
    {
      ProbeForWrite(a4, a5, 4);
      v14 = a6;
      ProbeForWrite(a6, 4, 4);
      v7 = v27;
    }
    else
    {
      v14 = a6;
    }
    v13 = SepCaptureUnicodeStringArray(v28, v7, v12, (int *)&v25);
    if ( v13 >= 0 )
    {
      v13 = SepReferenceTokenByHandle(v29, 8, v12, &v26, v23, _30);
      if ( v13 >= 0 )
      {
        v15 = __mrc(15, 0, 13, 0, 3);
        --*(_WORD *)((v15 & 0xFFFFFFC0) + 0x134);
        v10 = v26;
        ExAcquireResourceSharedLite(*(_DWORD *)(v26 + 48), 1);
        v24 = 1;
        v23[0] = 1;
        if ( v12 )
        {
          v21 = v14;
          v8 = v25;
          v13 = SepInternalQuerySecurityAttributesTokenEx(v10, v16, v25, v27, a4, a5, v21);
          v30 = v13;
          v9 = v24;
          goto LABEL_17;
        }
        v22 = v14;
        v8 = v25;
        v13 = SepInternalQuerySecurityAttributesTokenEx(v10, v16, v25, v27, a4, a5, v22);
LABEL_16:
        v9 = v24;
        goto LABEL_17;
      }
      v10 = v26;
    }
    v8 = v25;
    goto LABEL_16;
  }
  v13 = -1073741811;
LABEL_17:
  if ( v12 == 1 && v8 )
  {
    ExFreePoolWithTag(v8);
    v9 = v24;
  }
  if ( v9 )
  {
    v17 = ExReleaseResourceLite(*(_DWORD *)(v10 + 48));
    v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v19 = *(_WORD *)(v18 + 0x134) + 1;
    *(_WORD *)(v18 + 308) = v19;
    if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
      KiCheckForKernelApcDelivery(v17);
  }
  if ( v10 )
    ObfDereferenceObject(v10);
  return v13;
}
