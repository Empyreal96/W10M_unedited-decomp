// IopEtwEnableCallback 
 
int __fastcall IopEtwEnableCallback(int a1, int a2, int a3, int a4)
{
  __int64 v4; // r0
  __int64 v5; // r0

  if ( !a2 )
  {
    HIDWORD(v4) = 0;
    goto LABEL_5;
  }
  if ( a2 == 1 )
  {
    HIDWORD(v4) = 1;
LABEL_5:
    LODWORD(v4) = 1;
    IopIrpExtensionControl(v4, a3, a4);
  }
  return v5;
}
