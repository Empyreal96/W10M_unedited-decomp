// SeAuditHandleCreation 
 
int __fastcall SeAuditHandleCreation(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+70h] [bp+8h]

  varg_r0 = result;
  if ( *(_BYTE *)(result + 9) )
    return sub_7EA4DC();
  if ( *(_BYTE *)(*(_DWORD *)(result + 48) + 192) )
    JUMPOUT(0x7EA514);
  *(_BYTE *)(result + 10) = 0;
  return result;
}
