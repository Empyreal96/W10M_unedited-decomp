// _PnpCtxCloseMachine 
 
int __fastcall PnpCtxCloseMachine(_DWORD *a1)
{
  if ( a1[2] )
    ZwClose();
  if ( a1[3] )
    ZwClose();
  if ( a1[4] )
    ZwClose();
  if ( a1[5] )
    ZwClose();
  if ( a1[6] )
    ZwClose();
  if ( a1[7] )
    ZwClose();
  if ( a1[8] )
    ZwClose();
  if ( a1[9] )
    ZwClose();
  if ( *a1 )
    SysCtxCloseMachine(*a1);
  ExFreePoolWithTag((unsigned int)a1);
  return 0;
}
