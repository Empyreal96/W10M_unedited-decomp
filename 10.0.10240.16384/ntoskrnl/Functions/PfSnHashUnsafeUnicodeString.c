// PfSnHashUnsafeUnicodeString 
 
int __fastcall PfSnHashUnsafeUnicodeString(unsigned __int16 *a1, int *a2)
{
  int v2; // r3
  unsigned int v3; // r2
  unsigned __int8 *v4; // r4
  int v5; // r5
  int v6; // r0
  int v7; // t1
  int v8; // t1
  int v9; // t1
  int v10; // t1
  int v11; // t1

  v2 = *a1;
  if ( *a1 )
  {
    v3 = *((_DWORD *)a1 + 1);
    if ( (v3 & 1) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( v3 + v2 > MmUserProbeAddress || v3 + v2 < v3 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v4 = (unsigned __int8 *)*((_DWORD *)a1 + 1);
  v5 = *a1;
  v6 = 314159;
  while ( v5 >= 8 )
  {
    v6 = 37 * (37 * (37 * (37 * (37 * (37 * v4[1] + v4[2]) + v4[3]) + v4[4]) + v4[5]) + v4[6])
       + 442596621 * *v4
       - 803794207 * v6
       + v4[7];
    v4 += 8;
    v5 -= 8;
  }
  switch ( v5 )
  {
    case 1:
      goto LABEL_23;
    case 2:
LABEL_22:
      v11 = *v4++;
      v6 = 37 * v6 + v11;
LABEL_23:
      v6 = 37 * v6 + *v4;
      break;
    case 3:
LABEL_21:
      v10 = *v4++;
      v6 = 37 * v6 + v10;
      goto LABEL_22;
    case 4:
LABEL_20:
      v9 = *v4++;
      v6 = 37 * v6 + v9;
      goto LABEL_21;
    case 5:
LABEL_19:
      v8 = *v4++;
      v6 = 37 * v6 + v8;
      goto LABEL_20;
    case 6:
LABEL_18:
      v7 = *v4++;
      v6 = 37 * v6 + v7;
      goto LABEL_19;
    case 7:
      v6 = 37 * v6 + *v4++;
      goto LABEL_18;
  }
  *a2 = v6;
  return 0;
}
