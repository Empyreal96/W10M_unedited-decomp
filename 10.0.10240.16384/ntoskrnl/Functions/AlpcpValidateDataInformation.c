// AlpcpValidateDataInformation 
 
int __fastcall AlpcpValidateDataInformation(int a1, int a2)
{
  int v2; // r4
  unsigned int v4; // r2
  int result; // r0
  unsigned int *v6; // r1
  unsigned int v7; // r0

  v2 = *(unsigned __int16 *)(a2 + 2);
  v4 = *(unsigned __int16 *)(a2 + 6);
  if ( v4 < 0x18 || v4 > v2 - 12 )
    goto LABEL_2;
  v6 = (unsigned int *)(v4 + a1);
  v7 = (unsigned __int16)(v2 - v4) - 4;
  if ( ((v4 + a1) & 3) != 0 )
    ExRaiseDatatypeMisalignment(v7);
  if ( *v6 > v7 >> 3 )
LABEL_2:
    result = -1073741811;
  else
    result = 0;
  return result;
}
