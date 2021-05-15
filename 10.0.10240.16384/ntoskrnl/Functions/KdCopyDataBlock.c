// KdCopyDataBlock 
 
int __fastcall KdCopyDataBlock(int a1)
{
  int result; // r0

  if ( KdpDataBlockEncoded )
    result = sub_5521B8();
  else
    result = memmove(a1, (int)&KdDebuggerDataBlock, 0x360u);
  return result;
}
