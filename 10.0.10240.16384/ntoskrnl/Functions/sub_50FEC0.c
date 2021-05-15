// sub_50FEC0 
 
void sub_50FEC0()
{
  int v0; // r4
  __int64 v1; // r0

  *(_BYTE *)(v0 + 9) = 1;
  LODWORD(v1) = KeQueryInterruptTime();
  *(_QWORD *)(v0 + 16) = v1;
  PopTraceThermalStandbyInitiated(*(unsigned __int8 *)(v0 + 8));
  JUMPOUT(0x42642C);
}
