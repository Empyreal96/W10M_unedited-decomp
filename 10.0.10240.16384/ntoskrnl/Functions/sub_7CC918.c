// sub_7CC918 
 
void sub_7CC918(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r6
  int v9; // r7
  int v10; // r8
  int v11; // r10
  int v12; // [sp+78h] [bp+10h] BYREF
  va_list va; // [sp+78h] [bp+10h]
  int v14; // [sp+7Ch] [bp+14h]
  va_list va1; // [sp+80h] [bp+18h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  v12 = va_arg(va1, _DWORD);
  v14 = va_arg(va1, _DWORD);
  if ( !SdbpCheckKObject(v9, v10, v11, -1) )
  {
    SdbFindNextStringIndexedTag(v8, va1);
    JUMPOUT(0x770334);
  }
  if ( !SdbTagIDToTagRef(v9, v8, v10, (int *)va) )
    AslLogCallPrintf(1, (int)"SdbGetDatabaseMatchEx", 4465, "Failed to convert tiKObject to trKObject");
  JUMPOUT(0x770358);
}
