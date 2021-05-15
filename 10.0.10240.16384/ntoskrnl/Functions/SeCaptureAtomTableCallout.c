// SeCaptureAtomTableCallout 
 
int SeCaptureAtomTableCallout()
{
  int v0; // r0
  int v1; // r4
  int v3; // r3
  unsigned int *v4; // r1
  unsigned int v5; // r3
  unsigned int v6; // r0
  int v7; // r3
  unsigned int *v8; // r2
  unsigned int v9; // r1
  char v10[4]; // [sp+8h] [bp-18h] BYREF
  unsigned int v11; // [sp+Ch] [bp-14h] BYREF
  char v12[4]; // [sp+10h] [bp-10h] BYREF
  char v13[12]; // [sp+14h] [bp-Ch] BYREF

  v11 = 0;
  v0 = PsReferenceEffectiveToken(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v13, v10, v12, 0);
  v1 = v0;
  if ( (*(_DWORD *)(v0 + 176) & 0x4000) != 0 && !*(_DWORD *)(*(_DWORD *)(v0 + 628) + 24) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 288);
    __dmb(0xBu);
    if ( !v3 || (*(_DWORD *)(v3 + 204) & 0x20) == 0 )
    {
      PsInvokeWin32Callout(2, &v11, 0, 0);
      if ( v11 )
      {
        __dmb(0xBu);
        v4 = (unsigned int *)(*(_DWORD *)(v1 + 628) + 24);
        v5 = v11;
        do
          v6 = __ldrex(v4);
        while ( !v6 && __strex(v5, v4) );
        __dmb(0xBu);
        if ( !v6 )
        {
          v7 = v11;
          __dmb(0xBu);
          v8 = (unsigned int *)(v7 + 4);
          do
            v9 = __ldrex(v8);
          while ( __strex(v9 + 1, v8) );
          __dmb(0xBu);
        }
      }
    }
  }
  return ObfDereferenceObjectWithTag(v1);
}
