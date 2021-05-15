// RtlpAllowsLowBoxAccess 
 
BOOL __fastcall RtlpAllowsLowBoxAccess(int a1)
{
  int v3; // r4
  _BYTE *v4; // r0
  int v5; // r5
  __int16 *v6; // r1
  int v7; // r4
  int v8; // r6
  int v9; // r0
  char v10; // [sp+10h] [bp-C0h]
  char v11[4]; // [sp+20h] [bp-B0h] BYREF
  int v12; // [sp+24h] [bp-ACh] BYREF
  char v13[8]; // [sp+28h] [bp-A8h] BYREF
  int v14; // [sp+30h] [bp-A0h] BYREF
  char *v15; // [sp+34h] [bp-9Ch] BYREF
  int v16[2]; // [sp+38h] [bp-98h] BYREF
  int v17; // [sp+40h] [bp-90h]
  int v18; // [sp+44h] [bp-8Ch]
  _DWORD v19[4]; // [sp+48h] [bp-88h] BYREF
  char v20[8]; // [sp+58h] [bp-78h] BYREF
  int v21; // [sp+60h] [bp-70h]
  int v22[6]; // [sp+64h] [bp-6Ch] BYREF
  char v23; // [sp+80h] [bp-50h] BYREF

  v16[0] = 0;
  v16[1] = 0;
  v17 = 0;
  v18 = 0;
  v19[0] = 0x20000;
  v19[1] = 196608;
  v19[2] = 0x20000;
  v19[3] = 2031616;
  v21 = 0;
  memset(v22, 0, sizeof(v22));
  if ( (*(_WORD *)(a1 + 22) & 2) != 0 )
    return 1;
  if ( !byte_6417CC )
    return 0;
  RtlInitUnicodeString((unsigned int)v20, L"Global Atom Table Entry");
  v3 = *(unsigned __int8 *)(a1 + 24) + 1;
  v4 = (_BYTE *)ExAllocatePoolWithTag(1, 2 * v3);
  v5 = (int)v4;
  if ( v4 )
  {
    memset(v4, 0, 2 * v3);
    if ( RtlStringCbCopyW(v5, 2 * v3) < 0 )
      v6 = L"Unable to capture ATOM name.";
    else
      v6 = (__int16 *)v5;
  }
  else
  {
    v6 = L"Unable to Allocate space for ATOM name.";
  }
  RtlInitUnicodeString((unsigned int)v13, (unsigned __int16 *)v6);
  v22[1] = (int)v20;
  v22[2] = (int)v13;
  SeSetLearningModeObjectInformation();
  v15 = &v23;
  v7 = PsReferenceEffectiveToken(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, &v14, v11, &v12, 0);
  v17 = v7;
  v18 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 176);
  v10 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v8 = SeAccessCheckWithHint(SeAtomSd, 0, v16, 0, 0x20000u, 0, &v15, (int)v19, v10, &v12, &v14);
  v9 = ObfDereferenceObjectWithTag(v7);
  if ( v5 )
    v9 = ExFreePoolWithTag(v5);
  SeClearLearningModeObjectInformation(v9);
  return v8 == 1 && v12;
}
