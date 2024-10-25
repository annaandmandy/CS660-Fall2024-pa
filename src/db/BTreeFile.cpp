#include <cstring>
#include <db/BTreeFile.hpp>
#include <db/Database.hpp>
#include <db/IndexPage.hpp>
#include <db/LeafPage.hpp>
#include <stdexcept>

using namespace db;

BTreeFile::BTreeFile(const std::string &name, const TupleDesc &td, size_t key_index)
    : DbFile(name, td), key_index(key_index) {}

void BTreeFile::insertTuple(const Tuple &t) {
  // TODO pa2: implement
  
}

void BTreeFile::deleteTuple(const Iterator &it) {
  // Do not implement
}

Tuple BTreeFile::getTuple(const Iterator &it) const {
  // TODO pa2: implement
}

void BTreeFile::next(Iterator &it) const {
  // TODO pa2: implement
}

Iterator BTreeFile::begin() const {
  // TODO pa2: implement
  /*
  BufferPool &bufferPool = getDatabase().getBufferPool();
  size_t page = root_id;
  PageId pid;
  pid.file = name;
  pid.page = page;
  Page p = bufferPool.getPage(pid);
  IndexPage ip(p);
  ip.header->index_children
  return {*this, ip.keys[0], 0};
  */
  // return {*this, numPages, 0};
}

Iterator BTreeFile::end() const {
  // TODO pa2: implement
  return {*this, numPages, 0};
}
