// WmipProbeWnodeSingleItem 
 
int __fastcall WmipProbeWnodeSingleItem(_DWORD *a1, unsigned int a2)
{
  int result; // r0
  int v5; // r2

  if ( a2 < 0x44 )
    goto LABEL_7;
  result = WmipProbeWnodeWorker((int)a1, 0x44u, a1[12], a1[15], a1[16], a2, 0, 0, 1);
  if ( result < 0 )
    return result;
  v5 = a1[11];
  if ( (v5 & 4) != 0 && a2 == *a1 && (v5 & 0xFFFFFF7B) == 0 )
    result = 0;
  else
LABEL_7:
    result = -1073741823;
  return result;
}
