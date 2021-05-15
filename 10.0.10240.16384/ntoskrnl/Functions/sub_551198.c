// sub_551198 
 
void sub_551198()
{
  int v0; // r5
  int v1; // r6
  unsigned int v2; // r8
  int v3; // r4
  unsigned int v4; // r2
  char *v5; // r1

  v3 = *(_DWORD *)(v1 + 24);
  memset(&STACK[0x110], 0, 32);
  if ( PopPluginRequestDebuggerTransitionRequirements(v3, v2, &STACK[0x110]) )
  {
    v4 = 0;
    if ( v2 )
    {
      v5 = (char *)PopPepPlatformState;
      do
      {
        if ( *((_BYTE *)&STACK[0x110] + v4) )
        {
          if ( !v5[29] )
            PopFxBugCheck(1567, v3, v4, 0);
          *(_BYTE *)(v0 + 65) = 1;
          v5[28] = 1;
        }
        ++v4;
        v5 += 256;
      }
      while ( v4 < v2 );
    }
    PopDiagTraceDebuggerTransitionRequirements(v3, &STACK[0x110], v2);
  }
  JUMPOUT(0x4EE866);
}
