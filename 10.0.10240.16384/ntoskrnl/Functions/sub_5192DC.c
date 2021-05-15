// sub_5192DC 
 
void sub_5192DC()
{
  int v0; // r4
  int v1; // r5
  int v2; // r9

  ViTargetRemovingCheckEtwWmi(v0, v2);
  VfPoolCheckForLeaks(v0, v1);
  ViTargetRemovingCheckContiguousMemory(v0, v1);
  JUMPOUT(0x4DAA6E);
}
