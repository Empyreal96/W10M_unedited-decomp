// sub_54513C 
 
void sub_54513C()
{
  int v0; // r5
  int v1; // r6
  int v2; // r10
  int v3; // r0
  int v4; // r1
  int v5; // r2

  if ( MiCanPageMove(v0) )
  {
    if ( *(_BYTE *)(v1 + 32) )
    {
      v3 = MiSplitDriverPage(v2, *(unsigned __int8 *)(v1 + 44));
      if ( v3 < 0 )
      {
        if ( v3 != -1073741799 )
          JUMPOUT(0x4BD976);
        goto LABEL_10;
      }
    }
    else
    {
      MiUnlockProbePacketWorkingSet(v1);
      *(_BYTE *)(v1 + 32) = 1;
      MiLockProbePacketWorkingSet(v1, v4, v5);
    }
    JUMPOUT(0x4BD6A4);
  }
LABEL_10:
  JUMPOUT(0x4BD728);
}
