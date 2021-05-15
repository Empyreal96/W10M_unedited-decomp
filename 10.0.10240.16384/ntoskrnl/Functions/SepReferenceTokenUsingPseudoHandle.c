// SepReferenceTokenUsingPseudoHandle 
 
int __fastcall SepReferenceTokenUsingPseudoHandle(int a1, int *a2, _BYTE *a3, _DWORD *a4)
{
  int v7; // r5
  __int64 v8; // r0
  int v9; // r8
  char v11; // [sp+8h] [bp-20h] BYREF
  char v12; // [sp+9h] [bp-1Fh] BYREF
  char v13[2]; // [sp+Ah] [bp-1Eh] BYREF
  int v14; // [sp+Ch] [bp-1Ch] BYREF
  int v15[6]; // [sp+10h] [bp-18h] BYREF

  *a2 = 0;
  *a3 = 0;
  *a4 = 0;
  if ( a1 == -4 )
  {
    *a2 = PsReferencePrimaryToken(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    return 0;
  }
  if ( a1 == -5 )
  {
    v7 = PsReferenceImpersonationTokenEx(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0, v13, &v12, &v14, &v11);
    if ( !v7 )
      return -1073741700;
    goto LABEL_9;
  }
  v7 = PsReferenceEffectiveToken(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v15, &v12, &v14, &v11);
  if ( v15[0] == 2 )
  {
LABEL_9:
    if ( !v14 )
      return sub_52C6B4();
  }
  *a3 = 0;
  v12 = 0;
  *a4 = 0;
  v8 = SepSidFromProcessProtection(&v11);
  v9 = v8;
  RtlSidDominatesForTrust(v8, HIDWORD(v8), &v12);
  if ( !v12 )
  {
    *a3 = 1;
    *a4 = v9;
  }
  *a2 = v7;
  return 0;
}
