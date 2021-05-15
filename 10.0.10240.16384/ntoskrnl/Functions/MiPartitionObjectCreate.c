// MiPartitionObjectCreate 
 
int __fastcall MiPartitionObjectCreate(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int result; // r0
  _DWORD *v6; // r5
  int v7; // r0
  _DWORD *v8; // [sp+18h] [bp-18h] BYREF
  int v9[5]; // [sp+1Ch] [bp-14h] BYREF

  result = ObCreateObject(0, (_DWORD *)MmPartitionObjectType, a2, 0, 0, 4, 0, 0x4000, &v8);
  if ( result >= 0 )
  {
    v6 = v8;
    v7 = (int)v8;
    *v8 = MiSystemPartition;
    result = ObInsertObject(v7, 0, 2031619, 0, 0, (int)v9);
    if ( result >= 0 )
    {
      dword_63F704 |= 2u;
      unk_63F79C = v6;
      unk_63F7A0 = v9[0];
      *a5 = v6;
    }
  }
  return result;
}
