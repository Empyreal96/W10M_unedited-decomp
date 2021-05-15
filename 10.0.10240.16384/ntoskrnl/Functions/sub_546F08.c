// sub_546F08 
 
void sub_546F08()
{
  int v0; // r4
  int *v1; // r2

  if ( v0 == 1056 )
  {
    v1 = KFileEvt_NameCreate;
  }
  else
  {
    if ( v0 != 1059 )
      goto LABEL_6;
    v1 = KFileEvt_NameDelete;
  }
  EtwWrite(EtwpFileProvRegHandle, unk_61A92C, (int)v1, 0);
LABEL_6:
  JUMPOUT(0x4C328C);
}
