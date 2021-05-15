// sub_816724 
 
int sub_816724()
{
  int v0; // r5
  int v1; // r0
  int (__fastcall *v3)(int); // [sp+264h] [bp-4h]

  ZwClose();
  *(_DWORD *)(v0 + 16) = 0;
  v1 = SepAuditFailed();
  return v3(v1);
}
