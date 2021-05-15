// sub_51AE10 
 
void sub_51AE10()
{
  _DWORD *v0; // r6
  int v1; // r7

  MiAddMdlTracker(v0, (v0[5] + (((unsigned __int16)v0[6] + (unsigned __int16)v0[4]) & 0xFFFu) + 4095) >> 12, v1);
  JUMPOUT(0x441ED4);
}
