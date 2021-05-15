// WmipProbeWnodeMethodItem 
 
int __fastcall WmipProbeWnodeMethodItem(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  int result; // r0
  int v6; // r2

  if ( a2 < 0x44 )
    goto LABEL_7;
  result = WmipProbeWnodeWorker((int)a1, 0x44u, a1[12], a1[15], a1[16], a2, a3, 1, 1);
  if ( result < 0 )
    return result;
  v6 = a1[11];
  if ( (v6 & 0x8000) != 0 && a2 == *a1 && (v6 & 0xFFFF7F7F) == 0 )
    result = 0;
  else
LABEL_7:
    result = -1073741823;
  return result;
}
