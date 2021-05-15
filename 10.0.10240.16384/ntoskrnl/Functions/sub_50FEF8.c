// sub_50FEF8 
 
void sub_50FEF8()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  __int64 v3; // r0
  int v4; // r0

  *(_BYTE *)(v0 + 9) = 0;
  LODWORD(v3) = KeQueryInterruptTime();
  v4 = _rt_udiv64((unsigned int)dword_989680, v3 - *(_QWORD *)(v0 + 16));
  PopTraceThermalStandbyComplete(v1, v4, v2);
  JUMPOUT(0x426486);
}
