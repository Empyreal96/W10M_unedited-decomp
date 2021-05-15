// SepInformLsaOfDeletedLogon 
 
int __fastcall SepInformLsaOfDeletedLogon(_DWORD *a1, int a2, _DWORD *a3)
{
  int result; // r0
  int v6; // r3

  if ( !a3 )
    return sub_80A64C();
  a3[4] = *a1;
  v6 = a1[1];
  a3[11] = a2;
  a3[5] = v6;
  a3[6] = 3;
  a3[7] = 8;
  a3[8] = 0;
  a3[9] = 0;
  a3[3] = 0;
  a3[2] = 1;
  result = SepQueueWorkItem((int)&SepLsaDeletedLogonQueueInfo, a3, 0, 1);
  if ( !result )
  {
    if ( a2 )
      PspDereferenceSiloObject(a2);
    result = ExFreePoolWithTag((unsigned int)a3);
  }
  return result;
}
