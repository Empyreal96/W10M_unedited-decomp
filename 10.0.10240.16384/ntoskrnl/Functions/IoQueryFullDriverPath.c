// IoQueryFullDriverPath 
 
int __fastcall IoQueryFullDriverPath(int a1, int a2)
{
  int v2; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1
  int v7; // r0
  int v8; // r3
  unsigned int vars4; // [sp+Ch] [bp+4h]

  v2 = *(_DWORD *)(a1 + 20);
  if ( !v2 )
    return -1073741275;
  v5 = *(_DWORD *)(v2 + 24);
  if ( vars4 < v5 || vars4 > *(_DWORD *)(v2 + 32) + v5 )
    return -1073741790;
  v6 = *(unsigned __int16 *)(v2 + 38);
  if ( ViVerifierDriverAddedThunkListHead )
  {
    if ( (MmVerifierData & 0x10) != 0 )
      v8 = 40;
    else
      v8 = 32;
    v7 = ExAllocatePoolWithTagPriority(1, v6, 538996553, v8);
  }
  else
  {
    v7 = ExAllocatePoolWithTag(1, v6);
  }
  *(_DWORD *)(a2 + 4) = v7;
  if ( !v7 )
    return -1073741670;
  *(_WORD *)(a2 + 2) = *(_WORD *)(v2 + 38);
  RtlCopyUnicodeString((unsigned __int16 *)a2, (unsigned __int16 *)(v2 + 36));
  return 0;
}
