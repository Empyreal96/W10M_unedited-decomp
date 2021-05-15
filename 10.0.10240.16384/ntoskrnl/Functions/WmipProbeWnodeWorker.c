// WmipProbeWnodeWorker 
 
int __fastcall WmipProbeWnodeWorker(int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7, char a8, char a9)
{
  unsigned int v10; // r3

  if ( !a3 )
  {
LABEL_10:
    if ( a4 < a2 && a4 )
      return -1073741823;
    goto LABEL_11;
  }
  if ( a3 < a2 )
    return -1073741823;
  if ( ((a3 + 1) & 0xFFFFFFFE) != a3 )
    return -1073741823;
  if ( a3 > a6 - 2 )
    return -1073741823;
  v10 = *(unsigned __int16 *)(a1 + a3) + a3 + 2;
  if ( v10 > a6 )
    return -1073741823;
  if ( v10 > a7 )
    return sub_81AB4C();
  if ( a4 )
  {
    if ( a4 < v10 )
      return -1073741823;
    goto LABEL_10;
  }
LABEL_11:
  if ( ((a4 + 7) & 0xFFFFFFF8) == a4 && (!a9 || !a4 || a5 <= a6 && a4 <= a6 - a5) && (!a8 || a7 >= a2 && a4 <= a7 && a4) )
    return 0;
  return -1073741823;
}
