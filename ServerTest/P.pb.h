// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: P.proto

#ifndef PROTOBUF_P_2eproto__INCLUDED
#define PROTOBUF_P_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_P_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsmoveImpl();
void InitDefaultsmove();
void InitDefaultsvector3Impl();
void InitDefaultsvector3();
void InitDefaultspingImpl();
void InitDefaultsping();
inline void InitDefaults() {
  InitDefaultsmove();
  InitDefaultsvector3();
  InitDefaultsping();
}
}  // namespace protobuf_P_2eproto
namespace playerInfo {
class move;
class moveDefaultTypeInternal;
extern moveDefaultTypeInternal _move_default_instance_;
class ping;
class pingDefaultTypeInternal;
extern pingDefaultTypeInternal _ping_default_instance_;
class vector3;
class vector3DefaultTypeInternal;
extern vector3DefaultTypeInternal _vector3_default_instance_;
}  // namespace playerInfo
namespace playerInfo {

// ===================================================================

class move : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:playerInfo.move) */ {
 public:
  move();
  virtual ~move();

  move(const move& from);

  inline move& operator=(const move& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  move(move&& from) noexcept
    : move() {
    *this = ::std::move(from);
  }

  inline move& operator=(move&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const move& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const move* internal_default_instance() {
    return reinterpret_cast<const move*>(
               &_move_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(move* other);
  friend void swap(move& a, move& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline move* New() const PROTOBUF_FINAL { return New(NULL); }

  move* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const move& from);
  void MergeFrom(const move& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(move* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  const ::std::string& id() const;
  void set_id(const ::std::string& value);
  #if LANG_CXX11
  void set_id(::std::string&& value);
  #endif
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  ::std::string* mutable_id();
  ::std::string* release_id();
  void set_allocated_id(::std::string* id);

  // .playerInfo.vector3 position = 3;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 3;
  const ::playerInfo::vector3& position() const;
  ::playerInfo::vector3* release_position();
  ::playerInfo::vector3* mutable_position();
  void set_allocated_position(::playerInfo::vector3* position);

  // .playerInfo.vector3 rotation = 4;
  bool has_rotation() const;
  void clear_rotation();
  static const int kRotationFieldNumber = 4;
  const ::playerInfo::vector3& rotation() const;
  ::playerInfo::vector3* release_rotation();
  ::playerInfo::vector3* mutable_rotation();
  void set_allocated_rotation(::playerInfo::vector3* rotation);

  // .playerInfo.vector3 velocity = 5;
  bool has_velocity() const;
  void clear_velocity();
  static const int kVelocityFieldNumber = 5;
  const ::playerInfo::vector3& velocity() const;
  ::playerInfo::vector3* release_velocity();
  ::playerInfo::vector3* mutable_velocity();
  void set_allocated_velocity(::playerInfo::vector3* velocity);

  // int32 time = 2;
  void clear_time();
  static const int kTimeFieldNumber = 2;
  ::google::protobuf::int32 time() const;
  void set_time(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:playerInfo.move)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr id_;
  ::playerInfo::vector3* position_;
  ::playerInfo::vector3* rotation_;
  ::playerInfo::vector3* velocity_;
  ::google::protobuf::int32 time_;
  mutable int _cached_size_;
  friend struct ::protobuf_P_2eproto::TableStruct;
  friend void ::protobuf_P_2eproto::InitDefaultsmoveImpl();
};
// -------------------------------------------------------------------

class vector3 : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:playerInfo.vector3) */ {
 public:
  vector3();
  virtual ~vector3();

  vector3(const vector3& from);

  inline vector3& operator=(const vector3& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  vector3(vector3&& from) noexcept
    : vector3() {
    *this = ::std::move(from);
  }

  inline vector3& operator=(vector3&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const vector3& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const vector3* internal_default_instance() {
    return reinterpret_cast<const vector3*>(
               &_vector3_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(vector3* other);
  friend void swap(vector3& a, vector3& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline vector3* New() const PROTOBUF_FINAL { return New(NULL); }

  vector3* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const vector3& from);
  void MergeFrom(const vector3& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(vector3* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // float x = 1;
  void clear_x();
  static const int kXFieldNumber = 1;
  float x() const;
  void set_x(float value);

  // float y = 2;
  void clear_y();
  static const int kYFieldNumber = 2;
  float y() const;
  void set_y(float value);

  // float z = 3;
  void clear_z();
  static const int kZFieldNumber = 3;
  float z() const;
  void set_z(float value);

  // @@protoc_insertion_point(class_scope:playerInfo.vector3)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  float x_;
  float y_;
  float z_;
  mutable int _cached_size_;
  friend struct ::protobuf_P_2eproto::TableStruct;
  friend void ::protobuf_P_2eproto::InitDefaultsvector3Impl();
};
// -------------------------------------------------------------------

class ping : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:playerInfo.ping) */ {
 public:
  ping();
  virtual ~ping();

  ping(const ping& from);

  inline ping& operator=(const ping& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ping(ping&& from) noexcept
    : ping() {
    *this = ::std::move(from);
  }

  inline ping& operator=(ping&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ping& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ping* internal_default_instance() {
    return reinterpret_cast<const ping*>(
               &_ping_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(ping* other);
  friend void swap(ping& a, ping& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ping* New() const PROTOBUF_FINAL { return New(NULL); }

  ping* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ping& from);
  void MergeFrom(const ping& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ping* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  const ::std::string& id() const;
  void set_id(const ::std::string& value);
  #if LANG_CXX11
  void set_id(::std::string&& value);
  #endif
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  ::std::string* mutable_id();
  ::std::string* release_id();
  void set_allocated_id(::std::string* id);

  // string timer = 2;
  void clear_timer();
  static const int kTimerFieldNumber = 2;
  const ::std::string& timer() const;
  void set_timer(const ::std::string& value);
  #if LANG_CXX11
  void set_timer(::std::string&& value);
  #endif
  void set_timer(const char* value);
  void set_timer(const char* value, size_t size);
  ::std::string* mutable_timer();
  ::std::string* release_timer();
  void set_allocated_timer(::std::string* timer);

  // @@protoc_insertion_point(class_scope:playerInfo.ping)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr id_;
  ::google::protobuf::internal::ArenaStringPtr timer_;
  mutable int _cached_size_;
  friend struct ::protobuf_P_2eproto::TableStruct;
  friend void ::protobuf_P_2eproto::InitDefaultspingImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// move

// string id = 1;
inline void move::clear_id() {
  id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& move::id() const {
  // @@protoc_insertion_point(field_get:playerInfo.move.id)
  return id_.GetNoArena();
}
inline void move::set_id(const ::std::string& value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:playerInfo.move.id)
}
#if LANG_CXX11
inline void move::set_id(::std::string&& value) {
  
  id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:playerInfo.move.id)
}
#endif
inline void move::set_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:playerInfo.move.id)
}
inline void move::set_id(const char* value, size_t size) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:playerInfo.move.id)
}
inline ::std::string* move::mutable_id() {
  
  // @@protoc_insertion_point(field_mutable:playerInfo.move.id)
  return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* move::release_id() {
  // @@protoc_insertion_point(field_release:playerInfo.move.id)
  
  return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void move::set_allocated_id(::std::string* id) {
  if (id != NULL) {
    
  } else {
    
  }
  id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
  // @@protoc_insertion_point(field_set_allocated:playerInfo.move.id)
}

// int32 time = 2;
inline void move::clear_time() {
  time_ = 0;
}
inline ::google::protobuf::int32 move::time() const {
  // @@protoc_insertion_point(field_get:playerInfo.move.time)
  return time_;
}
inline void move::set_time(::google::protobuf::int32 value) {
  
  time_ = value;
  // @@protoc_insertion_point(field_set:playerInfo.move.time)
}

// .playerInfo.vector3 position = 3;
inline bool move::has_position() const {
  return this != internal_default_instance() && position_ != NULL;
}
inline void move::clear_position() {
  if (GetArenaNoVirtual() == NULL && position_ != NULL) {
    delete position_;
  }
  position_ = NULL;
}
inline const ::playerInfo::vector3& move::position() const {
  const ::playerInfo::vector3* p = position_;
  // @@protoc_insertion_point(field_get:playerInfo.move.position)
  return p != NULL ? *p : *reinterpret_cast<const ::playerInfo::vector3*>(
      &::playerInfo::_vector3_default_instance_);
}
inline ::playerInfo::vector3* move::release_position() {
  // @@protoc_insertion_point(field_release:playerInfo.move.position)
  
  ::playerInfo::vector3* temp = position_;
  position_ = NULL;
  return temp;
}
inline ::playerInfo::vector3* move::mutable_position() {
  
  if (position_ == NULL) {
    position_ = new ::playerInfo::vector3;
  }
  // @@protoc_insertion_point(field_mutable:playerInfo.move.position)
  return position_;
}
inline void move::set_allocated_position(::playerInfo::vector3* position) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete position_;
  }
  if (position) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      position = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:playerInfo.move.position)
}

// .playerInfo.vector3 rotation = 4;
inline bool move::has_rotation() const {
  return this != internal_default_instance() && rotation_ != NULL;
}
inline void move::clear_rotation() {
  if (GetArenaNoVirtual() == NULL && rotation_ != NULL) {
    delete rotation_;
  }
  rotation_ = NULL;
}
inline const ::playerInfo::vector3& move::rotation() const {
  const ::playerInfo::vector3* p = rotation_;
  // @@protoc_insertion_point(field_get:playerInfo.move.rotation)
  return p != NULL ? *p : *reinterpret_cast<const ::playerInfo::vector3*>(
      &::playerInfo::_vector3_default_instance_);
}
inline ::playerInfo::vector3* move::release_rotation() {
  // @@protoc_insertion_point(field_release:playerInfo.move.rotation)
  
  ::playerInfo::vector3* temp = rotation_;
  rotation_ = NULL;
  return temp;
}
inline ::playerInfo::vector3* move::mutable_rotation() {
  
  if (rotation_ == NULL) {
    rotation_ = new ::playerInfo::vector3;
  }
  // @@protoc_insertion_point(field_mutable:playerInfo.move.rotation)
  return rotation_;
}
inline void move::set_allocated_rotation(::playerInfo::vector3* rotation) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete rotation_;
  }
  if (rotation) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      rotation = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, rotation, submessage_arena);
    }
    
  } else {
    
  }
  rotation_ = rotation;
  // @@protoc_insertion_point(field_set_allocated:playerInfo.move.rotation)
}

// .playerInfo.vector3 velocity = 5;
inline bool move::has_velocity() const {
  return this != internal_default_instance() && velocity_ != NULL;
}
inline void move::clear_velocity() {
  if (GetArenaNoVirtual() == NULL && velocity_ != NULL) {
    delete velocity_;
  }
  velocity_ = NULL;
}
inline const ::playerInfo::vector3& move::velocity() const {
  const ::playerInfo::vector3* p = velocity_;
  // @@protoc_insertion_point(field_get:playerInfo.move.velocity)
  return p != NULL ? *p : *reinterpret_cast<const ::playerInfo::vector3*>(
      &::playerInfo::_vector3_default_instance_);
}
inline ::playerInfo::vector3* move::release_velocity() {
  // @@protoc_insertion_point(field_release:playerInfo.move.velocity)
  
  ::playerInfo::vector3* temp = velocity_;
  velocity_ = NULL;
  return temp;
}
inline ::playerInfo::vector3* move::mutable_velocity() {
  
  if (velocity_ == NULL) {
    velocity_ = new ::playerInfo::vector3;
  }
  // @@protoc_insertion_point(field_mutable:playerInfo.move.velocity)
  return velocity_;
}
inline void move::set_allocated_velocity(::playerInfo::vector3* velocity) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete velocity_;
  }
  if (velocity) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      velocity = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, velocity, submessage_arena);
    }
    
  } else {
    
  }
  velocity_ = velocity;
  // @@protoc_insertion_point(field_set_allocated:playerInfo.move.velocity)
}

// -------------------------------------------------------------------

// vector3

// float x = 1;
inline void vector3::clear_x() {
  x_ = 0;
}
inline float vector3::x() const {
  // @@protoc_insertion_point(field_get:playerInfo.vector3.x)
  return x_;
}
inline void vector3::set_x(float value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:playerInfo.vector3.x)
}

// float y = 2;
inline void vector3::clear_y() {
  y_ = 0;
}
inline float vector3::y() const {
  // @@protoc_insertion_point(field_get:playerInfo.vector3.y)
  return y_;
}
inline void vector3::set_y(float value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:playerInfo.vector3.y)
}

// float z = 3;
inline void vector3::clear_z() {
  z_ = 0;
}
inline float vector3::z() const {
  // @@protoc_insertion_point(field_get:playerInfo.vector3.z)
  return z_;
}
inline void vector3::set_z(float value) {
  
  z_ = value;
  // @@protoc_insertion_point(field_set:playerInfo.vector3.z)
}

// -------------------------------------------------------------------

// ping

// string id = 1;
inline void ping::clear_id() {
  id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ping::id() const {
  // @@protoc_insertion_point(field_get:playerInfo.ping.id)
  return id_.GetNoArena();
}
inline void ping::set_id(const ::std::string& value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:playerInfo.ping.id)
}
#if LANG_CXX11
inline void ping::set_id(::std::string&& value) {
  
  id_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:playerInfo.ping.id)
}
#endif
inline void ping::set_id(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:playerInfo.ping.id)
}
inline void ping::set_id(const char* value, size_t size) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:playerInfo.ping.id)
}
inline ::std::string* ping::mutable_id() {
  
  // @@protoc_insertion_point(field_mutable:playerInfo.ping.id)
  return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ping::release_id() {
  // @@protoc_insertion_point(field_release:playerInfo.ping.id)
  
  return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ping::set_allocated_id(::std::string* id) {
  if (id != NULL) {
    
  } else {
    
  }
  id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
  // @@protoc_insertion_point(field_set_allocated:playerInfo.ping.id)
}

// string timer = 2;
inline void ping::clear_timer() {
  timer_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ping::timer() const {
  // @@protoc_insertion_point(field_get:playerInfo.ping.timer)
  return timer_.GetNoArena();
}
inline void ping::set_timer(const ::std::string& value) {
  
  timer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:playerInfo.ping.timer)
}
#if LANG_CXX11
inline void ping::set_timer(::std::string&& value) {
  
  timer_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:playerInfo.ping.timer)
}
#endif
inline void ping::set_timer(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  timer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:playerInfo.ping.timer)
}
inline void ping::set_timer(const char* value, size_t size) {
  
  timer_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:playerInfo.ping.timer)
}
inline ::std::string* ping::mutable_timer() {
  
  // @@protoc_insertion_point(field_mutable:playerInfo.ping.timer)
  return timer_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ping::release_timer() {
  // @@protoc_insertion_point(field_release:playerInfo.ping.timer)
  
  return timer_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ping::set_allocated_timer(::std::string* timer) {
  if (timer != NULL) {
    
  } else {
    
  }
  timer_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), timer);
  // @@protoc_insertion_point(field_set_allocated:playerInfo.ping.timer)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace playerInfo

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_P_2eproto__INCLUDED