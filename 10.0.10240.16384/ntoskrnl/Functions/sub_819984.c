// sub_819984 
 
void __fastcall sub_819984(int a1)
{
  int v1; // r5

  *(_QWORD *)(a1 + 8) = SeSecurityPrivilege;
  *(_DWORD *)(a1 + 12 * (*(_DWORD *)a1)++ + 16) = v1;
  JUMPOUT(0x7B5A4E);
}
